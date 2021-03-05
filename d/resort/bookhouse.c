
inherit ROOM;

void create()
{
        set("short", "藏书阁");
        set("long", @LONG
藏书阁里没有其他，只有书，满壁满壁的书，东侧的书架上是乐谱，竟有《广
陵止息》的摹本，西侧的书架上堆满了铁雪山庄的武功秘笈。这些秘笈是多情刀客
铁少和多情剑客雪蕊儿半生心血的结晶。
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"back_yard",
	]));

       set("objects", ([
                BOOKS"force_100":	1,
                BOOKS"skill/fall-steps_50":	1,
                BOOKS"skill/meihua-shou_40":	1,
                BOOKS"skill/shortsong_40":	1,
                BOOKS"skill/qidaoforce_50":	1,
                BOOKS"skill/diesword_50":	1,
                __DIR__"obj/shelf" : 1,

        ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

