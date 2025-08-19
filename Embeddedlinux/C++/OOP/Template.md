### Explicit instantiation VS Explicit Specialisation
```
template <typename T> T max(T x, T y) { return x > y ? x : y; }
template char max(char a, char b); // Expilcit instantiation
template <> const char *max<const char *>(const char *x, const char *y) //Explicit Specialization
{

  

return strcmp(x, y) > 0 ? x : y;

}
int main() {}


```