// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "谷地");
        set("long", @LONG
远望四周，不由慨叹造物之神奇，原来这里被群峰环绕，且极低，似乎已在地
平之下，好似被巨灵踏上一脚而成的。顶上是厚厚的白云，所以无论在哪座峰上俯
视，都绝难见到这里。
LONG
        );
   set("exits", ([ 
      "northeast" : __DIR__"tianti1",
      "south" : __DIR__"dongkou",
   ]));

   set("outdoors","laowu");
	set("coor/x",150);
	set("coor/y",170);
	set("coor/z",10);
	setup();
   replace_program(ROOM);
}
