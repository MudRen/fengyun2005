inherit ROOM;
void create()
{
        set("short", "花海竹桥");
        set("long", @LONG
竹桥上交缠蔷薇、木香、刺梅、金雀，桥下撒满凤仙、鸡冠、秋葵等种。更有
那金萱、百合、剪春罗、剪秋罗、满地娇、缠枝牡丹等类，不可枚举。遇开放之时，
烂漫如锦屏。远离数尺，尽植名花异草。一花未谢，一花又开。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hehuadang",
  "northeast" : __DIR__"bamboo_bridge2",
]));
        set("objects", ([
        __DIR__"npc/yahuan" : 2,
                        ]) );
	set("outdoors","fengyun");
	set("coor/x",-20);
	set("coor/y",-5);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
