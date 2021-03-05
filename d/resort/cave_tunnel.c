
inherit ROOM;

void create()
{
        set("short", "穿山洞");
        set("long", @LONG
小径不远处是一个山洞，方圆丈许的山洞还留着人工斧凿的痕迹。涓涓的细流
顺着洞壁往下流，发出潺潺的水声。洞势渐渐升高，借着从出口处透入的天光，你
发现脚下的石级居然是汉白玉雕成的。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secret_road",
  "west" : __DIR__"another_sky",
]));
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

