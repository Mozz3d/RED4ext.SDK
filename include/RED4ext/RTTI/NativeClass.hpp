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
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const final
    {
        return DeepCompare(aLhs, aRhs, a3);
    }

    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const final
    {
        *static_cast<T*>(aDest) = *static_cast<T*>(aSrc);
    }

    virtual void OnConstruct(ScriptData* aMemory) const final
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    virtual void OnDestruct(ScriptData* aMemory) const final
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
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const final
    {
        return DeepCompare(aLhs, aRhs, a3);
    }

    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const final
    {
    }

    virtual void OnConstruct(ScriptData* aMemory) const final
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    virtual void OnDestruct(ScriptData* aMemory) const final
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
template<typename T>
struct [[deprecated("Use 'rtti::TNativeClass' or 'rtti::TNativeClassNoCopy' instead.")]] TTypedClass :
    std::conditional_t<std::is_copy_constructible_v<T>, rtti::TNativeClass<T>, rtti::TNativeClassNoCopy<T>>
{
};
} // namespace RED4ext
