inherit NPC;

void create()
{
        set_name("杀人蜂", ({ "killer bee","bee" }) );
        set("race", "昆虫");
        set("subrace","飞虫");
        set("age", 4); 
	
        set("long", "一只凶狠的杀人蜂。\n");

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
	if((what== "all" || what== "potion") && (where=="bell" || where=="金铃"))
	{
	message_vision("$N狠狠瞪了$n一眼，嗡嗡地向$n扑了上来！\n",this_object(),this_player());
	this_object()->kill_ob(this_player());
	this_player()->start_busy(2);
	return 1;
	}
}