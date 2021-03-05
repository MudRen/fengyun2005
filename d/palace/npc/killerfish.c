inherit NPC;

void create()
{
        set_name("食人鱼", ({ "killer fish","fish" }) );
        set("race", "游鱼");
        set("age", 4);

        set("long", "一条眼露凶光的食人鱼。\n");
        set("attitude", "aggressive");
        set_skill("dodge", 100);
	set_skill("move",300);
        set("combat_exp", 9000);
	set("bellicosity", 300 );
	add_temp("apply/damage",10+random(10));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
	add_action("do_get","get");
        }
}

int do_get(string arg)
{
	string what, where;
	if(!arg) return 0;
	if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
	if((what== "all" || what== "woodcase") && (where=="watergrass" || where=="水草"))
	{
	message_vision("$N狠狠瞪了$n一眼，一口向$n咬了上来！\n",this_object(),this_player());
	this_object()->kill_ob(this_player());
	this_player()->start_busy(2);
	return 1;
	}
}