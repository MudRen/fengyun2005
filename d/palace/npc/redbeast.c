// mind_beast.c

inherit NPC;

void create()
{
	set_name("怪兽", ({ "heaven lion", "lion" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这怪兽通体俱是赤红颜色，生得似狮非狮，似马非马。\n");
	
	set("str", 48);
	
	set("combat_exp", 200000);
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 140);

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( interactive(me))
                if( me->query("class") )
                if( me->query("class") != "yinshi") 
		kill_ob(me);

}
