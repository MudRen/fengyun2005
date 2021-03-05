// Snowlotus is one reboot each ( or more actually :D)
//	that's fine, let ppl expect some reboot.

inherit ROOM;
void create()
{
	object snow, lotus;
        set("short", "天山山脉");
        set("long", @LONG
这是天山东段最高峰博格达峰，为天山第二高峰，山峰终年积雪。峰顶冰川
纵横，景观绮丽。在博格达峰的山腰有一个碧蓝碧蓝的小湖，池水清澄，倒映着
蓝天白云，还有冰峰及苍尽翠绿的松林，让人感到无限的宁静。
LONG
        );
        set("exits", ([ 
		  	"northeast" : __DIR__"gela",
  			"northup" : __DIR__"tianchi",
		]));
        
        set("outdoors", "xinjiang");
		set("coor/x",0);
		set("coor/y",-90);
		set("coor/z",0);
		setup();
/*		snow = new(__DIR__"obj/snow");
		lotus= new(__DIR__"obj/lotus");
		snow->move(this_object());
		lotus->move(snow);*/
}
