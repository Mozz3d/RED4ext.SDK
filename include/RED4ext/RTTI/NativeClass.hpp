#pragma once

#include <RED4ext/RTTI/ClassType.hpp>

#include <algorithm>
#include <memory>

namespace RED4ext
{
namespace rtti
{

template<typename T>
struct TNativeClass : ClassType
{
    virtual bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3) const final
    {
        return DeepCompare(aLhs, aRhs, a3);
    }

    virtual void Copy(ScriptInstance aDest, const ScriptInstance aSrc) const final
    {
        *static_cast<T*>(aDest) = *static_cast<T*>(aSrc);
    }

    virtual void OnConstruct(ScriptInstance aMemory) const final
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    virtual void OnDestruct(ScriptInstance aMemory) const final
    {
        std::destroy_at(static_cast<T*>(aMemory));
    }

    virtual void* AllocMemory() const final
    {
        auto classAlignment = GetAlignment();
        auto alignedSize = AlignUp(GetSize(), classAlignment);

        auto allocator = GetAllocator();
        auto allocResult = allocator->AllocAligned(alignedSize, classAlignment);

        std::memset(allocResult.memory, 0, allocResult.size);
        return allocResult.memory;
    }
};

template<typename T>
struct TNativeClassNoCopy : ClassType
{
    virtual bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3) const final
    {
        return DeepCompare(aLhs, aRhs, a3);
    }

    virtual void Copy(ScriptInstance aDest, const ScriptInstance aSrc) const final
    {
    }

    virtual void OnConstruct(ScriptInstance aMemory) const final
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    virtual void OnDestruct(ScriptInstance aMemory) const final
    {
        std::destroy_at(static_cast<T*>(aMemory));
    }

    virtual void* AllocMemory() const final
    {
        auto classAlignment = GetAlignment();
        auto alignedSize = AlignUp(GetSize(), classAlignment);

        auto allocator = GetAllocator();
        auto allocResult = allocator->AllocAligned(alignedSize, classAlignment);

        std::memset(allocResult.memory, 0, allocResult.size);
        return allocResult.memory;
    }
};

} // namespace rtti
} // namespace RED4ext
