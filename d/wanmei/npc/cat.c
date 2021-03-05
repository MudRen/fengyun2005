inherit NPC;
void create()
{
    	set_name("小猫咪", ({ "cat" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只小小的，猫头猫脑的小花猫。\n");
    	set("combat_exp", 3000);
        set("attitude","peaceful");
        set_temp("apply/dodge", 100);
	set("chat_chance", 1);
        set("chat_msg", ({
	(: random_move :)
        }) );
        set("arrive_msg", "跳了过来");
        set("leave_msg", "＂喵～＂的一声，跳开了");
        setup();
}
