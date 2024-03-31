template<typename E>
constexpr typename std::underlying_type<E>::type
    toUType(E enumerator)noexcept{
        return static_cast<typename std::underlying_type<E>::type(enumerator);
}

template<typename E>
constexpr std::underlying_type_t<E>
    toUType(E enumerator)noexcept{
        return static_cast<std::underlying_type_t<E>>(enumerator);
}

template<typename E>
constexpr auto 
    toUType(E enumberator)noexcept{
        return static_cast<std::underlying_type_t<E>>(enumerator);
}

auto val = std::get<toUType(UserInfoFields::uiEmail)>(uInfo);

template<class C>
auto cbegin (const C& container)->decltype(std::begin(container)){
    retrun std::begin(container);
}