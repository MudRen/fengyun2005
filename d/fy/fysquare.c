#include <ansi.h>
#include <room.h>
inherit ROOM;

int count;

void create()
{
    set("short",HIR"风云天下"NOR);
    set("long", @LONG
风风雨雨，风云城的中心广场依旧鲜亮如新。风道天街和云街地巷在这里交会，
四方立起了宏伟的风云天地四个祭坛，昔日的广场却并无多少变化，虽然中央的水
池已经干涸，虽然当年碧绿的池水和尾尾金鱼不复存在，留下的是个几丈方圆，深
不见底的大洞。水池旁的蟠龙摩天石柱饱经岁月沧桑，依然不屈不挠地耸立，石柱
上九条飞龙张牙舞爪，直欲冲天而去。往高处走一步，便是天下闻名的[1;31m天机阁[0;32m。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"tiandoor",
	"south" : __DIR__"yundoor",
	"east" : __DIR__"didoor",
	"west" : __DIR__"fengdoor",
	"up":	__DIR__"fysquareu",

//	"down" : "/d/pk/entry",
	//		"up" : "/obj/dungeon/standardmaze/mingyue/entry",
	//		"up2" : "/obj/dungeon/standardmaze/blanche/entry",

      ]));
    set("outdoors", "fengyun");
	set("tianji_square",1);
	
    set("objects", ([
		
//	"/d/bashan/npc/so":1,
      ]) );

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",0);
    set("no_dazuo",1);
    set("no_study",1);
    
    count=0;
    set("time",time());
    setup();
    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/fysquare_b", "盘龙摩天柱");
}

void reset(){
	::reset();
	message("system", ""HIC"【闲聊】"NOR HIY"天机老人(Tian ji)"HIW": [1;31m风起云涌，天地变色，万物复苏，英雄辈出。[0;32m \n",users());
	set("time",time());
//	message("system", HIC"【闲聊】"NOR HIY"天机老人(Tian ji)"HIW ":" +sprintf("当前时间:%s \n",ctime(time())),users());
	count++;
}
int do_jump(string arg)
{
        object room, me=this_player();
        if( !arg || arg != "up" ) return 0;

        room = get_object( "/adm/daemons/fairyland_quest/room_door_hj" );
        if( !room ) return 0;
        
    if(me-> sizeof( query_temp("protectors"))){
     write("幻境不允许带兵进入，还是遣散了吧。\n");
     return 0;
    }

        tell_room(environment(me),me->query("name")+"使劲地往上一跳，突然卷来一阵旋风，"+
                me->query("name")+"顿时被风刮得不知所踪。\n",me);
        

        write("你使劲地往上一跳，忽地平地卷起一阵旋风，恍惚中你已来到了「幻境」。\n");
        me->move(room);
        tell_room(room,"忽然一阵旋风袭过，"+me->query("name")+"已出现在这里。\n",me);
        return 1;
}
void init()
{
    
        add_action("do_jump", "jump");
}

int refresh(){
	int x;	
	x= 900+query("time")-time();
	if (count>1)
	     return x;
	else
		return 99999;
}

int valid_leave(object who, string dir) {
	if (dir == "up") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",1);
		}
	}
	return ::valid_leave(who,dir);
}