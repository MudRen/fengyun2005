#include <ansi.h>

inherit NPC;
void create()
{
    set_name("小猫咪", ({ "kitten" }) );
    set("nickname",YEL"黄"HIW"白"NOR"相间");
    set("race", "野兽");
    set("age", 1);
    set("gender", "雌性");
    set("long", "这是一只黄白相间的小猫咪，正蹲在草丛中玩弄着嫩草。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
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
    message_vision("机灵的$N一窜就上了树，不见了踪影。\n",this_object());
    destruct(this_object());
}

int accept_object(object who, object ob)
{
    if(ob->query("marks/catfood"))
    {
        message_vision(sprintf(
            "$N走了过来，舔舔你的手把%s叼走了。\n", ob->name()),this_object());
        return 1;
    }
	return notify_fail("小猫低头嗅了嗅，转身跳了开去。\n");
}
        
