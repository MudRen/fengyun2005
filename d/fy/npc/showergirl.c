inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("小丫环", ({ "little yahuan","yahuan" }) );
	set("gender", "女性" );
	set("age", 14);
	set("title", "如花似玉");
	set("long",
		"一个天真无邪的小丫环\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,
	]) );
    	set("inquiry", ([
        	"fatman" : (: tell_him :),
        	"大胖子" : (: tell_him:),
        ]));
	set_skill("unarmed",5);
	set_skill("tenderzhi",5);
	set_skill("dodge",5);
	set_skill("stormdance",5);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
message_vision("$N在百忙中抬起头望了$n一眼。\n",this_object(),ob);
			break;
	}
}
int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"小丫鬟道：他天天都来，今天也来过，刚刚走！\n");
    
    if (REWARD_D->riddle_check(me,"失剑风波")==3 
    	|| REWARD_D->riddle_check(me,"失剑风波")==4 ) {
		tell_object(me,"他总是丢三拉四的，你进去找找(search)说不定还可以发现他拉下的东西。\n");
		REWARD_D->riddle_set(me,"失剑风波",4);
	}
    
    return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,
	]) );	
}