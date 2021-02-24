namespace helper
{
    template <int... Is>
    struct index {};

    template <int N, int... Is>
    struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

    template <int... Is>
    struct gen_seq<0, Is...> : index<Is...> {};
}

template <typename... Ts>
class Action : public IJob
{
private:
    std::function<void(Ts...)> func;
    std::tuple<Ts...> args;
public:
    template <typename F, typename... Args>
    Action(F&& func, Args&&... args)
        : func(std::forward<F>(func)),
        args(std::forward<Args>(args)...)
    {}

    template <typename... Args, int... Is>
    void Func(std::tuple<Args...>& tup, helper::index<Is...>)
    {
        func(std::get<Is>(tup)...);
    }

    template <typename... Args>
    void Func(std::tuple<Args...>& tup)
    {
        Func(tup, helper::gen_seq<sizeof...(Args)>{});
    }

    virtual void operator()() override { Call(); };

    virtual void Call() override {
        Func(args);
    }
};