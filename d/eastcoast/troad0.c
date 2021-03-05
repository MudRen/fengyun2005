
inherit ROOM;

void create()
{
        set("short", "山谷口");
        set("long", @LONG
路边立着一块石碑，上面写着三个古篆字：[33m『大旗谷』[32m。往谷中看去，一条弯
弯曲曲的小路伸向深处，在一危崖前突然中断。
LONG
        );
        set("exits", ([ 
 		 "west" : __DIR__"troad0a",
  		"eastdown" : __DIR__"troad1",
]));
	set("outdoors","tieflag"); 	
        
	set("coor/x",400);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}
