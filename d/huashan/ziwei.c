
inherit ROOM;

void create()
{
        set("short", "紫薇洞");
        set("long", @LONG
此处是一孔依崖凿刻的人工山洞。洞外绿树成荫，青草遍地，树荫下有一巨
石形如卧虎，似在把守着洞口，几棵修竹依崖靠近洞口而生，弯弯的翠竹似在向
洞内张望。洞内供奉着北极太皇大帝塑像，两侧文武拥护，栩栩如生。
LONG
        );
    set("exits", ([ 
  		"westdown" : __DIR__"zhuyu",
	]));
	set("objects", ([
		__DIR__"obj/tstone" : 1,
		__DIR__"obj/bamboo" : 1,
		__DIR__"npc/bonze" : 1,
	]));
    set("indoors", "huashan");
	
	set("coor/x",15);
	set("coor/y",10);
	set("coor/z",-20);
	setup();
    replace_program(ROOM);
}

