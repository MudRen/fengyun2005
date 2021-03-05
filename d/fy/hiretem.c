#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "城隍古庙");
    set("long", @LONG
这庙少说也有几百年的历史，据说在风云城兴起之前就有了，自从修起了地坛，
庙里的香火越来越少，庙内阴暗潮湿，破旧不堪，每当狂风吹过，庙墙抖抖索索，
似乎马上就会倒塌下来，香案上只有一支残烛在风中摇曳，忽明忽暗，鬼气森森。
灰尘满布的庙内，唯有角落里的一个暗红色的神龛却是一尘不染。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north"  : __DIR__"didoor", 
      ]));
    set("item_desc", ([
		"kan": "这个神龛开口很窄，正好可扔下一张纸(throw)。\n",
		"神龛" : "这个神龛开口很窄，正好可扔下一张纸(throw)。\n"
    ]) );
    set("revive_area",1);
    set("objects", ([
		"/obj/specials/ding/ding_fy" : 1,
		__DIR__"npc/monk" : 1,
    ]) );

    set("coor/x",40);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_throw", "throw");
}

int do_throw(string arg)
{
    object *inv;
    object me, who;
    object paper;
    object killer;
    string target;
    int targetprice;
    int i;
    if (!arg) return notify_fail("你要放什么入神龛？\n");
    if( arg !="youzhi" && arg != "油油的纸")
		return notify_fail("你不可把"+arg+"放入神龛．\n");
    
    me = this_player();
    who = this_player();
    
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
    {
		if( (string)(inv[i]->query("name")) == "油油的纸")
		{
	    	paper = inv[i];		
	    	break;
		}
    }
    if( !paper) return notify_fail("你没有油油的纸．\n");
    if( !stringp(paper->query("targetid")))
		return notify_fail("你的纸上没写字。\n");
        
    if (query("limit")<1)
		return notify_fail("神龛里满满地都是纸条，你赛不进去耶，过一会儿吧。\n");
    
    if (who->is_busy())
		return notify_fail("你现在正忙。\n");	
    who->perform_busy(2);
    
    target = (string)paper->query("targetid");
    
    killer = new(__DIR__"npc/killer");
    killer->set("possessed",who);
    killer->set_leader(who);
    killer->set("haunttar", target); 
    
    targetprice = (int)paper->query("targetprice");
    destruct(paper);
    
    killer->set("combat_exp", targetprice);		// 以 coin 为单位
    
    targetprice = F_LEVEL->get_level(targetprice) + 20;
    
    killer->set_skill("sword", targetprice);
    killer->set_skill("parry",targetprice);
    killer->set_skill("lefthand-sword", targetprice);
    killer->set_skill("pyrobat-steps",targetprice);
    killer->set_skill("dodge", targetprice);
    "/feature/nada"->reset_npc(killer);
    
    if (killer->query("max_kee")>9000)	killer->set("max_kee",9000);
    if (killer->query("max_sen")>9000)	killer->set("max_sen",9000);
    if (killer->query("max_gin")>9000)	killer->set("max_gin",9000);
    
    killer->full_me();
    message_vision("$N阴笑一声，面目阴陈的把纸放入神龛．\n",who);
    
    log_file("KILL_LOG",sprintf("(%s)%s雇了杀手杀%s\n",
    	ctime(time()),
		who->query("id"),
		killer->query("haunttar")));
    
    add("limit",-1);
    call_out("gothim", 2, who,killer);
    return 1;
}


void gothim(object who, object killer)
{
    if(who && killer) {
	message_vision(BLU"一阵阴风掠过，$N不禁打了个冷战．\n"NOR,who);
	killer->move(this_object());
	if (environment(who) == this_object())
	    message_vision("$N向$n低声道：带我去．．\n",killer,who);
    }
    if (QUESTS_D->verify_quest(who,"城隍黑影"))
    	QUESTS_D->special_reward(who,"城隍黑影");
    
    return;
}

void reset(){
    set("limit",3);
    ::reset();
}
