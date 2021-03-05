
inherit ROOM;

void create()
{
        set("short", "谷内小径");
        set("long", @LONG                 
在灌木从中一条弯弯曲曲的小路伸向谷内。小路十分光滑，象是经常有人走动。
从灌木中不时跳出一只兔子，在你眼前一晃，又跳没影了。
LONG
        );
        set("exits", ([ 
           	"westup" : __DIR__"troad0",
  	  	"north" : __DIR__"troad2",
        
         ]));                                  
	set("objects",([
              AREA_TIEFLAG"npc/rabbit" : 1,
        ]));
	set("outdoors","tieflag"); 	
	
	set("coor/x",610);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
