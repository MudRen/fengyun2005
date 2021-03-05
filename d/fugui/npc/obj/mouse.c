
inherit NPC;

void create()
{
        set_name("小老鼠", ({ "mouse" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只饿得皮包骨头，瘦骨嶙峋，可怜巴巴的小老鼠。\n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);

        setup();
}

