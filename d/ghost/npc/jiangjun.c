#include <ansi.h>
inherit NPC;

void create()
{
        set_name("将军", ({ "jiang jun" }) );
        set("gender", "男性");
        set("class", "ghost");
        create_family("幽灵山庄", 2, "弟子");
        set("combat_exp", 50000);
        set("reward_npc", 1);
	set("difficulty", 1);
        set("no_arrest",1);
        set("long",
		"身高八尺八寸，体重一百七十三斤，宽肩，阔胸，双腿粗如树干。\n"
	);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 100);
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 100);
        set_skill("bloodystrike", 100);
	map_skill("iron-cloth", "jin-gang");
	map_skill("unarmed", "bloodystrike");
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();

}

void init()
{
	object	me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
	if (!objectp(me) || environment(me)!= environment() || me->is_ghost()) 
		return 1;
	if( (string)me->query("family/family_name")!="幽灵山庄" ) {
		message_vision(HIY "\n$N放下木勺对$n喝道：" + me->name() + "！锅里是肉！来不来？\n"NOR, this_object(), me);
	}
	return 1;
}
