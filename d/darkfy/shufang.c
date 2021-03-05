inherit ROOM;
void create()
{
        set("short", "知府书房");
        set("long", @LONG
这书室庭户虚敞，正中挂一幅名人山水。供一个古铜香炉，炉里香烟飘渺。左边
设一张湘妃竹榻，右边架上堆满若干图书。沿窗一只几上，摆列文房四宝。窗外庭中
种植许多花木，铺设得十分清雅，凡朝廷命官都可在这发号令（ａｒｒｅｓｔ）。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"govern",
]));
        set("objects", ([
        __DIR__"npc/governor" : 1,
                        ]) );

        set("coor/x",-19);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
}

