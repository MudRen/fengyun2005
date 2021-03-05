
inherit NPC;

void create()
{
        set_name("沙虫", ({ "sandworm" }) );
        set("race", "蛇类");
        set("age", 15);
        set("long", "一条水桶粗细的沙虫，竟有一丈多长，张大着血盆大口向你扑来。\n");

        
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", 200000);
	set("bellicosity", 30000 );
	set("str",80);
	set_temp("apply/attack",400);
	set_temp("apply/dodge",400);
	set_temp("apply/damage",150);
        setup();
        carry_object(__DIR__"obj/liver");
}
