
inherit NPC;
void create()
{
	set_name("瞎老爹", ({ "laodie", "lao die" }) );
	set("gender", "男性" );
	set("age", 55);
	set("title", "盲乐师");
	set("long","
没有人知道瞎老爹的来历，也没人注意他是哪一天到这里的，更没有人知道，
哪一天他又会离开．．．瞎老爹和他的女儿莲儿常在这儿给大家唱一两支小
曲儿，也籍此勉强谋生。他面目苍沧桑，皱纹横布。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",15);
	set_skill("unarmed",50);
	set_skill("dodge",50);

	setup();
   	carry_object("obj/music/erhu")->wield();
   	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
   	object	lianer;

	if( !ob || environment(ob) != environment() ) return;
        lianer = present("lian er", environment(ob));
        if(!objectp(lianer)){
message_vision("$N说：＂这位"+RANK_D->query_respect(ob)+"见到我的莲儿了吗?＂\n",this_object(),ob);
           return;
        }
        if(query_temp("marks/sing") == 1) {
           	return;
        }
	switch( random(2) ) {
		case 0:
message_vision("$N调了调琴弦，说：＂莲儿，给客人唱个小调儿吧。＂\n",this_object(),ob);
			break;
		case 1:
message_vision("$N调了调琴弦，说：＂这位"+RANK_D->query_respect(ob)+
"要听个小曲吗? ＂\n",this_object(),ob);
			break;
	}
        this_object()->set_temp("marks/sing", 1);
        lianer->do_sing(ob);
}
