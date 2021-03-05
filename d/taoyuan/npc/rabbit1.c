inherit NPC;

void create()
{
        set_name("野兔", ({ "rabbit" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", 
"一只白尾巴的野兔，尾巴翘一翘的正在潭边喝水，看来很容易就可以抓(catch)到。\n");
        set("max_kee", 90);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
		set("NO_KILL","这么可爱的兔子，还是不要杀了吧，到嵩山什么的去找找其他的？\n");
        set_skill("dodge", 100);

        setup();
}
