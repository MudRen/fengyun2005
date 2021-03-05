// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "风云神" NOR, ({ "supergod" }) );
	set("age", 7006);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);
	
	set("NO_KILL","开玩笑吧？想崩溃系统么？\n");
	
	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
        message("system",
                HIW     "风云在五分钟后重新启动（ＲＥＢＯＯＴ）。\n\n" NOR,
                users() );
    call_out("countdown", 60, 5);

}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIR	"\t\t风云在" + chinese_number(min) + "分钟后重新启动（ＲＥＢＯＯＴ）！\n\n",
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "风云重新启动（ＲＥＢＯＯＴ）．．．\n",
			users() );
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
        object *user, link_ob;
        int i;
        user = users();
        for(i=0; i<sizeof(user); i++) {
                if( !environment(user[i]) ) continue;
                user[i]->save();
                link_ob = user[i]->query_temp("link_ob");
                if( objectp(link_ob) ) link_ob->save();
        }
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n你听到一声带著愤恨、惊恐、与野兽般的咆哮声响彻整个天空。\n\n"
		HIW "风云神" HIR "嘶哑地吼著：可恶的" + ob->name(1) + "，我一定会报仇的～～～\n\n"
			"然後一道黑色火焰呼啸著冲上云端，大地又恢复了宁静。\n\n" NOR,
		users() );
	destruct(this_object());
}
