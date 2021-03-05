
inherit ROOM;

void create()
{
        set("short", "舍身崖");
        set("long", @LONG
传说古时有个孝子，为还愿报答神灵为其父母治病，在此处舍身跳崖。探头向
下望去，崖壁直立，深有百丈，崖底沟壑交错，溪流盘环，令人目眩胆颤，不由得
倒退数步。非有绝大的勇气与决心是不可能跳得下去的。
LONG
        );
    set("exits", ([ 
        "northeast" : __DIR__"lianhua",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-85);
	set("coor/y",-63);
	set("coor/z",40);
    set("objects", ([
		__DIR__"npc/kuan" : 1,
	]));  
    
	setup();
    replace_program(ROOM);
}

