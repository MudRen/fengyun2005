// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "叠嶂峰");
        set("long", @LONG
这里山峰实在是多，相传黄山三千六百峰，从叠嶂峰来看，只怕尤有过之，仅
次一处山峰便难以计算，群峰叠嶂，都是一根而出，看似群峰，也难说清究竟该有
多少，好在有石阶，铁索，游人便可以比较轻松的到达后山的松谷庵。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qingliang",
  "west" : __DIR__"sroad",
]));
        set("objects", ([
        __DIR__"npc/dizi" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-130);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
