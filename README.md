# binutils

http://core.ring.gr.jp/pub/GNU/binutils/

```
cd binutils-2.41
./configure --target=h8300-elf --disable-nls --prefix=/home/pojiro/TomboWorks/project/step12/local
```

# gcc

http://core.ring.gr.jp/pub/GNU/gcc/gcc-13.2.0/

```
cd gcc-13.2.0
mkdir build
cd build
../configure --target=h8300-elf --disable-nls --disable-threads --disable-shared --disable-libssp --enable-languages=c --prefix=/home/pojiro/TomboWorks/project/step12/local
```

# h8write

http://mes.osdn.jp/h8/writer-j.html

```
gcc h8write.c -o h8write -Wall
mv h8write /home/pojiro/TomboWorks/project/step12/local/bin/
```

# xmodem with screen

[Send file by xmodem or kermit protocol with GNU screenl](https://unix.stackexchange.com/questions/56614/send-file-by-xmodem-or-kermit-protocol-with-gnu-screen)
