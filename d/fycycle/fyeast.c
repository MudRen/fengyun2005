inherit ROOM;

void create()
{
    set("short", "风云东 ");
    set("long", @LONG
这是风云城东的一个市集，一条布满车痕的官道向西方和东方伸展。东北面群
山起伏，云雾缭绕不知其真面目，向南左右两边都是一望无际的庄稼地，远处苍松
翠柏中便是道家圣地武当山。
LONG
    );
    set("exits", ([ 
	"west" : AREA_FY"egate",
	"east" : AREA_EASTCOAST"palace_path1",
	"south" : __DIR__"sroad6",
	"north" :__DIR__"road6",
      ]));
    set("outdoors", "fycycle");
    set("coor/x",320);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}



int valid_leave(object me, string dir)
{
//  object *inv,ob;
//  int i;

    if( userp(me))
    {
	if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 1)
	    me->set_temp("annie/xiangsi_enterance",2);
	else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 5)
	    me->set_temp("annie/xiangsi_enterance",6);
	else
	    me->delete_temp("annie/xiangsi_enterance");
    }
    return 1;
}