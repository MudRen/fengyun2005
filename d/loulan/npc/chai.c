#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();
int show_me();

void create()
{
        set_name("快活王", ({ "master chai","master","chai" }) );
        set("gender", "男性" );
        set("long","
广额高颧，面白如玉，颔下一部长髯，光洁如缎。长眉如卧蚕，双目细而长，
微微下垂的眉目，闪闪发着光，当中配着高高耸起而多肉的钩鼻，象征着无
比的威权，深沉睿智，也象征着他那绝非常人可比的旺盛精力。\n");

        set("nickname", HIY"万家生佛"NOR );
	set("apprentice_available", 5);
	set("class","knight");
	
	create_family("快活林", 1, "塞北之王");
		set("rank_nogen",1);
	    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"侍酒童","寻欢客","敛财客","药师","铁骑士","铁骑卫",
    			"铁骑统领","铁骑使","酒使","色使","财使","气使",
    			RED"快活右使"NOR,RED"快活左使"NOR,RED"一字并肩王"NOR,HIR"快活王"NOR}));
        set("attitude", "peaceful");
        
        set("reward_npc", 1);
	set("difficulty", 40);
	
	set("age", 57);
        set("per", 10);
        set("agi", 80);
                
        set("combat_exp", 20000000);
        
	set("chat_chance_combat",80);
        set("chat_msg_combat",({
	        (:perform_action,"axe.jiuqipoxiao":),
	        (:perform_action,"dodge.fengliu":),
        }));
        
        set_temp("apply/haste",400);
        set("toughness",200);      
            
    	set("inquiry", ([
            	"leave" : (: leave :),
    	]));
        	        
        set("chat_chance", 1);
        set("chat_msg", ({
		"快活王捋捋长髯大笑道：明日大喜礼毕，便是我柴玉关马踏中原之时！\n",
		"快活王端起夜光杯，一口饮下，长笑道：壮志饥餐胡虏肉，笑谈渴饮匈奴血。\n如今且饮这葡萄美酒，他日当喝中原人的血酒！\n",
		}) );

        
        set_skill("foreknowledge", 190);
	set_skill("axe", 300);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	    
	    set_skill("force", 160);    
        set_skill("unarmed", 160);
        set_skill("move", 170);
        set_skill("perception",170);
        set_skill("chanting",100);
        set_skill("literate",100);
        
        set_skill("xuanyuan-axe", 180);
        set_skill("dream-herb", 200);
        set_skill("windy-steps", 200);
        set_skill("longlife-force", 180);
        set_skill("herb", 300);
        set_skill("hanshan-strike",200);
        
                      
          map_skill("unarmed","hanshan-strike");
          map_skill("herb","dream-herb");
          map_skill("axe","xuanyuan-axe");
          map_skill("parry","xuanyuan-axe");
          map_skill("dodge","windy-steps");
          map_skill("force","longlife-force");
          map_skill("move","windy-steps");
          
        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
        carry_object(__DIR__"obj/panguaxe")->wield();
        carry_object(__DIR__"obj/lightcup");
}


void reset()
{
	set("apprentice_available", 5);
}


void attempt_apprentice(object me)
{
        if( (string)me->query("class") != "knight" )
        {
            command("say 我只收本门弟子，你还是另寻良师吧！\n");
        }
        else if (!REWARD_D->check_m_success(me,"楼兰孽缘"))
        {
        	command("say 等老夫大婚之后再说吧！\n");
        }
        else if(!me->query_temp("marks/knight_win_dugu"))
        {
        	switch ( random(2) )
		{
		  	case 0:
				command("say 本门规矩森严，先打赢你的师傅再来找我！\n");
				break;
			case 1:
		  		command("say 学武要循序渐进，你还是打好基础再来吧。\n");
		  		break;
		}
		}
		else
		{
			command("say 你天纵英才，乃我门中希望，我一身功夫后继有人啊！呵呵！\n");
			command("recruit " + me->query("id") );
		}
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
	add_action("do_answer","answer");
	add_action("do_accept","accept");
}


void greeting(object me)
{
	object *inv;
	int i;
	object ob;
	ob = this_object();
	if( userp(me))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="方心骑" 
					&& (int)inv[i]->query("equipped"))
			{
				if (!me->query_temp("marks/chai_talkto_you"))
				{
					message_vision(HIY"$N目光如刀，朝你望了过来．．． \n"NOR,ob);
					message_vision(HIY"$N颔首道：＂心骑，去告知王妃速去百花宫上妆，喜娘们都齐了，知道么？\n（answer yes or not) ＂\n"NOR,ob);
					me->set_temp("marks/chai_talkto_you",1);
				}
				else
				{
					message_vision(HIY"$N问道：＂心骑，事情办得怎样？\n"NOR,ob);	
				}
			}
		}
	}
}

int do_answer(string arg)
{    
	object me;
	
	me=this_player();
	if (!arg) return notify_fail("回答什么？\n");
	if (!me->query_temp("marks/chai_talkto_you")) return notify_fail("回答什么？\n");
	if (arg == "yes")
	{
		message_vision("$N毕恭毕敬躬身答应。\n",me);
		me->set_temp("marks/chai_get_command",1);
		return 1;
	}
	else if (arg == "no")
	{
		message_vision("$N脸上微一犹豫．．． \n",me);
		message_vision("$N脸色一沉：好大的胆，不听本王的话！你到底是何人！ ．．． \n",this_object());
		me->delete_temp("marks/chai_talkto_you");
		this_object()->kill_ob(me);
      		me->kill_ob(this_object());
      		return 1;
	}
	else
		return notify_fail("回答什么？\n");
}

int accept_object(object me, object obj)
{	
       	object npc;
//     	object book;
       	object *inv;
	int i;
	int j;
	j = 0;
	npc = this_object();
	if( userp(me))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="方心骑" && (int)inv[i]->query("equipped"))
			{
				j = 1;
			}
		}
	}
       	if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "樟木镶金箱" && j == 1)
       	{
			if (obj->query("closed")){
				message_vision(YEL"$N一挑眉说：“心骑，你不快去办事，给本王这个箱子作甚？”\n"NOR,npc);
				return 0;
			}
			message_vision(HIY"$N霍然站起，看着镶金箱半晌无语．．．\n"NOR,npc);
			message_vision(HIY"$N卧蚕眉一挑，仰天狂笑道：云梦妖妇！莫当本王无知，嘿嘿．．． \n"NOR,npc);
			message_vision(HIY"$N重重拍着$n的肩膀道：好，心骑，不愧为本王急风第一骑！ 
你立此大功，可拜入我门下学习！ \n"NOR,npc,me);
	        REWARD_D->riddle_done( me, "楼兰孽缘",50,1);	
	         	
	        return 1;
        }
        else
        	return notify_fail("快活王抚须微笑，默然不语。\n");	
}



int leave() {
	if (this_player()->query("class")!="knight") return 0;
	message_vision(CYN"$N一脚踢在$n的屁股上。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：以后你的轩辕斧使不利索可别怪我。\n"NOR,this_object(),this_player());
	message_vision(CYN"$N说：孤王的云梦五花锦也得留下。\n"NOR,this_object(),this_player());
	return 1;
}
