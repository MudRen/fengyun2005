inherit ROOM;
void create()
{
        set("short", "小街南端");
        set("long", @LONG
再往南已没有路，东侧是李大娘的庄园。太平镇八十三户人家，一半是武镇山
武三爷的，另一半就是李大娘的。没有人知道大娘真名叫什么，也没人知道她的来
历，只知道她三年前买下了这座庄园。三丈高墙上倒插着锋刃，庄院沉浸在一种莫
名的神秘阴森之中。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"mroad7",
		"southeast": __DIR__"mroad9",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door":	"漆黑的大门紧紧地关着。\n",		    
		"大门":	"漆黑的大门紧紧地关着。\n",
	]));
	set("coor/x",-20);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}

