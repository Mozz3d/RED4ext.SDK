#pragma once

struct IRenderData
{
	using AllocatorType = Memory::RenderDataAllocator;

    virtual Memory::IAllocator* GetAllocator()
    {
        return AllocatorType::Get();
    }

    virtual void Destroy()
    {
        if (this)
        {
            Memory::Delete(this);
        }
    }

    virtual ~IRenderData() = default;

    void Release()
    {
        if (--refCount < 1)
            Destroy();
    }

    void AddRef()
    {
        refCount++;
    }

    std::atomic<int32_t> refCount = 1;
};
RED4EXT_ASSERT_SIZE(IRenderData, 0x10);

template<std::derived_from<IRenderData> T = IRenderData>
struct TRenderPtr
{
    TRenderPtr() = default;

    ~TRenderPtr()
    {
        Release();
    }

    TRenderPtr(const TRenderPtr& aOther)
        : data(aOther.data)
    {
        if (data)
            data->AddRef();
    }

    TRenderPtr& operator=(const TRenderPtr& aOther)
    {
        if (this != &aOther)
        {
            Release();

            data = aOther.data;
            if (data)
                data->AddRef();
        }
        return *this;
    }

    TRenderPtr(TRenderPtr&& aOther) noexcept
        : data(aOther.data)
    {
        aOther.data = nullptr;
    }

    TRenderPtr& operator=(TRenderPtr&& aOther) noexcept
    {
        if (this != &aOther)
        {
            Release();

            data = aOther.data;
            aOther.data = nullptr;
        }
        return *this;
    }

    T* operator->() const
    {
        return data;
    }

    // swap?

    void Release()
    {
        if (data)
            data->Release();
    }

    T* GetPtr() const
    {
        return data;
    }

    T* data = nullptr;
};
RED4EXT_ASSERT_SIZE(TRenderPtr<>, 0x08);