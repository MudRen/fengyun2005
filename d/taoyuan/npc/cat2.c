#include <ansi.h>

#define DROP_CMD "/cmds/std/drop"

inherit NPC;
void create()
{
    set_name("小猫咪", ({ "kitten" }) );
    set("nickname",HIW"浑身雪白"NOR);
    set("race", "野兽");
    set("age", 1);
    set("gender", "雌性");
    set("long", "浑身雪白的小猫咪像一个小雪球在地上翻滚跳跃着追逐着一个红色的小球。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
    set("redball", 1);
    set("chat_msg", ({
        "小猫咪喵喵叫了几声。\n",
        "小猫咪打了个滚儿。\n",
        "小猫咪用爪子碰了碰你。\n",
        (: random_move :)
            }) );
    set("chat_chance", 5);

    set("verbs", ({ "bite","claw" }) );
    set("arrive_msg", "悄无声息地走了过来。");
    set("leave_msg", "＂喵～＂的一声，跳了开去。");
    setup();
}

int kill_ob(object me)
{
    message_vision("机灵的$N叼着小球一窜就上了树，不见了踪影。\n",this_object());
    destruct(this_object());
}

int accept_object(object who, object ob)
{
 	object me;
 	
 	me = this_player();
 	
    if(ob->query("marks/catfood"))
    {
        object obj;
//        DROP_CMD->main(this_object(),obj->id());
		message_vision("小雪球一样的猫咪跳了过来，低头在" + me->name() +
				"手上拱了拱，对着" + me->name() + "喵喵~~~\n"
				+ "叫了几声衔走了" + ob->name() + "\n",this_object());
  		if(ob->name() == "五彩小鱼" && query("redball")) {
  			obj = new(__DIR__"obj/redball");
  			if(!objectp(obj)){
  				obj = new(__DIR__"obj/redball1");
  			}
  			obj->move(environment());
  			message_vision("一个红色的小球从$N嘴里掉了下来。\n", this_object());
     		set("long", "浑身雪白的小猫咪像一个小雪球在地上翻滚跳跃着。\n");
     		set("redball", 0);
     	}
	    return 1;
    }
    return notify_fail(this_object()->name() + "低头嗅了嗅" + ob->name() + "，转身跳了开去。\n");
}
        
