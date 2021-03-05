
inherit ROOM;
void close_path();
void create()
{
        set("short", "风云雅阁");
        set("long", @LONG
这里专门招待江湖上万儿极响亮的人物。能有幸坐在这儿的，不是一掷千金的豪客，
就是跺跺脚江湖四颤的一方霸主。整间房子的中央只有一张上等翠玉打磨成的八仙桌，
桌上放着四只御赐金杯。三面的墙上挂满了字画，剩下的一面是一道一垂及地的红布
挂帘。
LONG
        );
        set("exits", ([
                "down" : __DIR__"fyge",
//		"east" : __DIR__"fysf",
//		"north", __DIR__"fysecret",
        ]));

        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",-290);
        setup();
}
