

```

[ capture clause ] (parameters) -> return-type
{
	definition of method
}

----------------------

int main()
{
auto func = [] (int first , int second)
{

return first + second;
};

func(2,3);
return 0;
}


---------------------

== insights ==


#include<iostream>

int main()
{
    
  class __lambda_5_13
  {
    public: 
    inline /*constexpr */ int operator()(int first, int second) const
    {
      return first + second;
    }
    
    using retType_5_13 = int (*)(int, int);
    inline constexpr operator retType_5_13 () const noexcept
    {
      return __invoke;
    };
    
    private: 
    static inline /*constexpr */ int __invoke(int first, int second)
    {
      return __lambda_5_13{}.operator()(first, second);
    }
    
    
  };
  
  __lambda_5_13 func = __lambda_5_13{};
  std::cout.operator<<(func.operator()(2, 3));
  return 0;
}


```

