inherit NPC;
#include <ansi.h>
int tongqian();

void create()
{
	set_name("乙成仙", ({ "fortune teller","teller" }) );
	set("gender", "男性" );
	set("age", 45);
	set("title",HIY  "生死已卜"NOR);
	set("long",	"这位＂生死已卜＂的乙成仙正满眼诡密的望着你。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
		
	set("inquiry", ([
            "碧绿铜钱" : (: tongqian :),
             "铜钱" : (: tongqian :),
              "coin" : (: tongqian :),
   	]));
   	
   	set("max_force",1000);
   	set("force", 1000);
	
	set_skill("unarmed",250);
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/daopao")->wear();
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
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
message_vision("$N向$n说道：你印堂发黑，刹气透天庭，三天！三天之内一定横尸街头。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N对$n阴笑一声：你还是去订口棺材吧！\n",this_object(),ob);
			break;
		case 2:
message_vision("$N望了$n一眼，一家大小老少都完了．．．．\n",this_object(),ob);
			break;
                case 3:
message_vision("$N自言自语地说：我怎么会丢了师傅给的碧绿铜钱？\n",this_object(),ob);
                        break;
	}
}

int accept_object(object who, object ob)
{
        if((string) ob->query("marks") == "special_green_coin")
        {
         //       who->set("marks/green_coin",1);
				REWARD_D->riddle_set( who,"勇探地牢",1);
				tell_object(who,"乙成仙道：好！你帮我找到了铜钱，我来真正给你算一卦！\n");
				tell_object(who,"你真的是煞气冲天，你一定要在三天之内订口棺材，可能躲过这一劫！\n");
                return 1;
        }
        return 0;
}

int tongqian() {
	message_vision("$N说：铜钱是师傅传给我用来算卦用的，可是上次从沉香镇回来后就找不到了。\n",this_object());
	message_vision("$N说:如果你替我找回它，我一定给你好好算一卦!\n", this_object());
	return 1;
	}
	
	