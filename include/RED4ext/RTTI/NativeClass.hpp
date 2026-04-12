#pragma once

#include <RED4ext/RTTI/IType.hpp>

namespace RED4ext
{
namespace rtti
{
template<typename T>
struct TNativeClass : ClassType
{
    static_assert(std::is_class_v<T>, "T must be a struct or class");
    static_assert(std::is_default_constructible_v<T>, "T must be default-constructible");
    static_assert(std::is_destructible_v<T>, "T must be destructible");

    TNativeClass(CName aName, ClassType::Flags aFlags = {.isNative = true})
        : ClassType(aName, sizeof(T), aFlags)
    {
    }

    const bool IsEqual(const void* aLhs, const void* aRhs, uint32_t a3 = 0) final // 48
    {
        // This is doing something extra beside comparing properties, using the native func until we figure it out.
        using func_t = bool (*)(TNativeClass<T>*, const void*, const void*, uint32_t);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::TTypedClass_IsEqual);
        return func(this, aLhs, aRhs, a3);
    }

    void Assign(void* aLhs, const void* aRhs) const final // 50
    {
        new (aLhs) T(*static_cast<const T*>(aRhs));
    }

    void ConstructCls(void* aMemory) const final // D8
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    void DestructCls(void* aMemory) const final // E0
    {
        std::destroy_at(static_cast<T*>(aMemory));
    }

    void* AllocMemory() const final // E8
    {
        auto classAlignment = GetAlignment();
        auto alignedSize = AlignUp(GetSize(), classAlignment);

        auto allocator = GetAllocator();
        auto allocResult = allocator->AllocAligned(alignedSize, classAlignment);

        std::memset(allocResult.memory, 0, allocResult.size);
        return allocResult.memory;
    }
};
RED4EXT_ASSERT_SIZE(TNativeClass<CName>, sizeof(CClass));

template<typename T>
struct TNativeClassNoCopy : ClassType
{
    static_assert(std::is_class_v<T>, "T must be a struct or class");
    static_assert(std::is_default_constructible_v<T>, "T must be default-constructible");
    static_assert(std::is_destructible_v<T>, "T must be destructible");

    TNativeClassNoCopy(CName aName, ClassType::Flags aFlags = {.isNative = true})
        : ClassType(aName, sizeof(T), aFlags)
    {
    }

    const bool IsEqual(const void* aLhs, const void* aRhs, uint32_t a3 = 0) final // 48
    {
        // This is doing something extra beside comparing properties, using the native func until we figure it out.
        using func_t = bool (*)(TTypedClass<T>*, const void*, const void*, uint32_t);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::TTypedClass_IsEqual);
        return func(this, aLhs, aRhs, a3);
    }

    void Assign(void* aLhs, const void* aRhs) const final // 50
    {
    }

    void ConstructCls(void* aMemory) const final // D8
    {
        std::construct_at(static_cast<T*>(aMemory));
    }

    void DestructCls(void* aMemory) const final // E0
    {
        std::destroy_at(static_cast<T*>(aMemory));
    }

    void* AllocMemory() const final // E8
    {
        auto classAlignment = GetAlignment();
        auto alignedSize = AlignUp(GetSize(), classAlignment);

        auto allocator = GetAllocator();
        auto allocResult = allocator->AllocAligned(alignedSize, classAlignment);

        std::memset(allocResult.memory, 0, allocResult.size);
        return allocResult.memory;
    }
};
RED4EXT_ASSERT_SIZE(TNativeClassNoCopy<CName>, sizeof(CClass));
} // namespace rtti
} // namespace RED4ext
