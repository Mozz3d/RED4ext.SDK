#pragma once

#include <RED4ext/Utils.hpp>
#include <RED4ext/Memory/Allocators.hpp>

namespace RED4ext::red
{
// DynArray wrapper for type erased/generic access
struct DynArrayAccessor
{
    void Swap(DynArrayAccessor& aOther)
    {
        std::swap(m_entries, aOther.m_entries);
        std::swap(m_size, aOther.m_size);
        std::swap(m_capacity, aOther.m_capacity);
    }

    void ShrinkToSize(uint32_t aElementSize, uint32_t aAlignment)
    {
        if (m_size < m_capacity)
            ResizeBuffer(m_size, aElementSize, aAlignment);
    }

    void Resize(uint32_t aSize, uint32_t aElementSize, uint32_t aAlignment)
    {
        if (aSize != m_size)
        {
            if (m_capacity < aSize)
            {
                while (m_capacity < aSize)
                {
                    m_capacity += (m_capacity < 2) ? 1 : (m_capacity / 2);
                }
                ResizeBuffer(m_capacity, aElementSize, aAlignment);
            }
            m_size = aSize;
        }
    }

    void ResizeExact(uint32_t aSize, uint32_t aElementSize, uint32_t aAlignment)
    {
        if (aSize != m_size)
        {
            if (m_capacity < aSize)
            {
                ResizeBuffer(aSize, aElementSize, aAlignment);
            }
            m_size = aSize;
        }
    }

    inline void ResizeBuffer(uint32_t aCapacity, uint32_t aElementSize, uint32_t aAlignment)
    {
        using func_t = void (*)(DynArrayAccessor*, uint32_t, uint32_t , uint32_t, void*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::DynArray_Realloc);
        func(this, aCapacity, aElementSize, aAlignment, nullptr);
    }

    void* GetElement(uint32_t aElementSize, uint32_t aIndex) const
    {
        if (aIndex < m_size)
        {
            return static_cast<uint8_t*>(m_entries) + (aElementSize * aIndex);
        }
        return nullptr;
    }

    bool Empty() const
    {
        return m_size == 0;
    }

    void* Data() const
    {
        return m_entries;
    }

    void SetAllocator(const Memory::IAllocator* aAllocator)
    {
        if (m_capacity == 0)
        {
            m_entries = const_cast<Memory::IAllocator*>(aAllocator);
        }
    }

    uint32_t Capacity() const
    {
        return m_capacity;
    }

    uint32_t Size() const
    {
        return m_size;
    }

    void Clear() // no destruction because no type safety
    {
        m_size = 0;
    }

    void* m_entries;
    uint32_t m_capacity;
    uint32_t m_size;
};

struct StaticArrayAccessor
{
    void* Data() const
    {
        return std::bit_cast<void*>(this);
    }

    uint32_t& SizeRef(uint32_t aElementSize, uint32_t aMaxSize)
    {
        uint32_t offset = aElementSize * aMaxSize;
        uintptr_t sizePtr = AlignUp((std::bit_cast<uintptr_t>(this) + offset), alignof(uint32_t));
        return *std::bit_cast<uint32_t*>(sizePtr);
    }

    uint32_t Size(uint32_t aElementSize, uint32_t aMaxSize)
    {
        return SizeRef(aElementSize, aMaxSize);
    }

    void Resize(uint32_t aElementSize, uint32_t aMaxSize, uint32_t aSize)
    {
        SizeRef(aElementSize, aMaxSize) = aSize;
    }

    void* GetElement(uint32_t aElementSize, uint32_t aMaxSize, uint32_t aIndex)
    {
        if (aIndex < Size(aElementSize, aMaxSize))
        {
            return std::bit_cast<uint8_t*>(Data()) + aIndex;
        }
        return nullptr;
    }

    void Clear(uint32_t aElementSize, uint32_t aMaxSize)
    {
        Resize(aElementSize, aMaxSize, 0);
    }
};

struct NativeArrayAccessor
{
    void* Data() const
    {
        return std::bit_cast<void*>(this);
    }

    void* GetElement(uint32_t aElementSize, uint32_t aMaxSize, uint32_t aIndex)
    {
        if (aIndex < aMaxSize)
        {
            return std::bit_cast<uint8_t*>(Data()) + aIndex;
        }
        return nullptr;
    }
};

} // namespace RED4ext::ref
