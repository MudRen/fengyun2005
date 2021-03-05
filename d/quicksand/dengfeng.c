// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "登封县城");
        set("long", @LONG
青石街道随着越来越接近山区变得坎坷起来，由于来来往往的游客极多，所以
作为登少室山必经之路的登封县城分外的热闹，道路两边店铺林立，上山所需的一
切，这里应有尽有。道路的南面有一家铁铺和一家布铺。西北便是上山道，很大的
路牌上写着[33m『嵩山少林寺』[32m由此前行。
LONG
        );
        set("exits", ([ 
  		"east" : "/d/fycycle/fywest",
  		"west" : __DIR__"xiaodao1",
  		"northwest" : AREA_SONGSHAN"qimu",
  		"southeast" : __DIR__"bupu",
  		"southwest" : __DIR__"tiepu",
]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-600);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
