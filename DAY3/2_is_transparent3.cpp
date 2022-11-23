#include <iostream>
#include <string>
#include <set>

template <typename T = void>
struct less
{
    inline bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

template <>
struct less<void>
{
    template<typename T1, typename T2>
    [[nodiscard]] constexpr auto operator()(T1&& lhs, T2&& rhs) const
        noexcept(noexcept(std::forward<T1>(lhs) < std::forward<T2>(rhs)))
        -> decltype(std::forward<T1>(lhs) < std::forward<T2>(rhs))
    {
        return std::forward<T1>(lhs) < std::forward<T2>(rhs);
    }
};



//--------------------------------------
struct People
{
	std::string name;
	int age;
	People(const std::string& name, int age) : name(name), age(age) {}
};
bool operator<(const People& p1, const People& p2) { return p1.name < p2.name; }
bool operator<(const People& p1, const std::string& name) { return p1.name < name; }
bool operator<(const std::string& name, const People& p2) { return name < p2.name; }

int main()
{
//	std::set<People, std::less<void>  > s;

    std::set<People, less<void>  > s;

	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	auto ret1 = s.find(People("bbb", 30));
	auto ret2 = s.find("bbb");
}
