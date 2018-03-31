#! /bin/sh

rm -f cscope.* tags
find $(pwd) -name '*.cpp' -o -name '*.h' -o -name '*.c' -o -name '*.hpp' -o -name '*.cc' -o -name '*.cxx' > src.files
cscope -bkq -i src.files
ctags -R --c++-kinds=+px --fields=+iaS --extra=+q -L src.files
rm -f src.files
