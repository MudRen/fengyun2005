inherit ROOM;

void create()
{
	set("short", "三清湖");
	set("long", @LONG
湖水清澈透明，不时可以看到几尾鱼跳上水面。湖水尽头是一个大瀑布，从山
上直冲而下，水波激荡，雾气弥漫，发出如雷般的轰鸣声。湖边一块巨石，上面写
着“神仙窟宅，灵异之府”八个龙飞凤舞的大字。
LONG
	);
	set("exits", ([ 
  		"west" : __DIR__"grassland1",
  		"north" : __DIR__"lake2",
		]));
         set("objects", ([ 
                __DIR__"npc/watcher_taoist" : 1,
                __DIR__"npc/feng" : 1,
		]));
 
        set("resource/water",1);
        set("liquid", ([
        	"container":"三清湖",
        	"name":  "三清湖水",
        ]));
        
		set("outdoors", "taoguan");
		set("coor/x",10);
		set("coor/y",-40);
		set("coor/z",0);
		setup();
}

