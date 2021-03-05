// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "探海松");
        set("long", @LONG
树木逐渐稀疏，路边不时冒出的古松却各具姿色，有的雄壮挺拔，有的婀娜多
姿，带给你种种惊喜。不远处一棵高大的松树斜长在山石旁，一茂密的枝杆探向危
崖，崖下终年雾海茫茫，就犹如一只巨臂探象茫茫的云海。
LONG
        );
        set("exits", ([ 
  "northeast"  : __DIR__"jiyu",
  "southeast" : __DIR__"guanyin",

]));
        set("outdoors", "huangshan");
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
