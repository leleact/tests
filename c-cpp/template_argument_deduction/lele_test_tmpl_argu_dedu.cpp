template <typename To, typename From> To convert(From f);

void g(double d) {
    int i = convert<int>(d);
}
