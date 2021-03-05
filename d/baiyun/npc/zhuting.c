inherit SMART_NPC;

#include <ansi.h>
int ask_for();

void create()
{

        set_name("朱停", ({ "zhu ting","zhu" }) );
        set("gender", "男性" );
        set("nickname",HIC"妙手"NOR);
        set("age", 42);
        set("long", "朱停是个很懂得享受的人，而且对什么事都很看得开。胖的人看
来总是很有福气的样子，有福气的人才能做老板。\n");

        set("combat_exp", 3800000);
        set("chat_chance", 1);
        set("chat_msg", ({

        		"朱停懒懒地看了你一眼，低下头继续在太师椅上打着呼噜。\n",
		        "朱停笑了笑道：你若也有我这样一个漂亮的婆娘，便什么也想开了。\n",
		        "朱停痴痴地坐在太师椅上，不知在胡思乱想什么。\n",
		}) );

        set("attitude", "friendly");

        set("inquiry", ([
           "剑" : (: ask_for :), 
           "sword" : (: ask_for :),
        ]) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
        setup();
        carry_object("/d/fugui/npc/obj/m_cloth2")->wear();

}



int accept_fight(object me)
{

        command("say 连我这种懒人你都不放过，天理何在啊！\n");
        return 0;

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

void greeting(object me)
{
        object sword;
        
        if (!me 
        	|| environment(me) != environment())	
        	return;
        if(!me->query("sword_carrier")) {
        	
        	
        	
        	
        	return ;
        }
        if(me->query("sword_carrier")+1080>time())
		{
			ccommand("shake");
			ccommand("say 除了帮你修剑，我还得吃，还得睡，还得合欢，还得如厕，哪里能这么快？");
			return;
		}
        if (!me->query("marks/zhu_8sword"))
        {
	  	message_vision( HIG "三日仿佛千年，在你等得焦头烂额，心急如焚之际。。。。
          朱停缓缓从内屋走了出来，双手捧上"HIC "『天剑』" HIG "，小心翼翼交给你手中。
          \n\n朱停冷冷道：若不是千年的岁月磨去了这天剑的血煞之气，一百个老朱的命赔进去也铸不成这把大凶之剑！
          朱停叹了口气道：拿去吧，自己好自为之！ \n"NOR,me);
        	sword=new(__DIR__"obj/fixed_8sword");
        	sword->move(me); 
			me->set("marks/zhu_8sword",1);
        	me->delete("sword_carrier");
        }   
                                 
		return ;

}


int ask_for()
{
        object me;
        
        me=this_player();       
        if(me->query("marks/zhu_8sword")) 
        {
                message_vision("朱停伸了个懒腰，撇撇嘴道：“上次你不是来过回么，小店从不接待回头客。”\n",me);
                return 1;
        }
        if(me->query_temp("search_zhu_sword"))
        {
        message_vision(HIC "朱停懒洋洋道：八剑缺一不可 。。。\n"NOR,me);
                return 1;
        }

      message_vision(HIC 
"朱停轻轻拍着圆滚滚的肚子懒懒道：越王八剑本是一块玄铁陨石分为八块而造，据说昔年这位铸剑大家
本只造了一把王道之剑，但剑成时天地失色，血光漫天，殊为不祥，是分为八剑。这位"+RANK_D->query_respect(me)+"
要想重铸这把天剑，则定需集齐八剑不可！"NOR, me);
    message_vision(HIW "\n朱停微微睁开朦胧睡眼，茫然看了看你，又继续呼呼大睡。\n"NOR,me);
        me->set_temp("search_zhu_sword",1);
        return 1;
}

string *material_names=({
    "断掉的掩日", "断掉的断水", "断掉的转魄", "断掉的悬翦",
"断掉的惊鲵","断掉的灭魂","断掉的却邪","断掉的真刚"        });

int accept_object(object me, object ob)
{
        string ob_name;
        int i,success,sword_ok;
        
        if(!me->query_temp("search_zhu_sword")) 
                return 0;
                
        ob_name=ob->query("name");
        success=1;
        sword_ok=0;
      	for(i=0;i<8;i++)
        {
                if(ob_name==material_names[i])
                {
                        if(me->query_temp("zhu/"+ob_name))
                        {
                                message_vision("朱停奇声道：“怎么又是这把？难道是赝品？”\n",me);
                                return 0;
                        } 
                           me->set_temp("zhu/"+ob_name,1);
                           message_vision("朱停双手捧剑，庸懒之态一扫而光，庄重道：多谢这位“"+RANK_D->query_respect(me)+"将"+ob_name+"找到，一代名剑，怎能埋于黄土之中！”\n",me);
                           sword_ok=1;
                           return 1;    
                }
                        success=success*me->query_temp("zhu/"+material_names[i]);
        }
       if (sword_ok = 1)
       { 
        if(!success) return 0;
        sword_ok = sword_ok + 1;
        command("spank "+me->query("id"));
        message_vision(HIC "朱停不大的双目炯炯放光，连声赞道：不错，不错，王道天剑，终于又可重见天日了！ \n"NOR,me);
        message_vision(YEL"朱停抬头望了你一眼：请三日后取剑。\n"NOR,me);
        me->set("sword_carrier",time());
        me->delete("search_zhu_sword");
        call_out("make_sword",1080,me);
        } else {
               message_vision("朱停怒道：“什么垃圾都给我？”\n",me);
	       return 0;
        }
  return 0;
}



void make_sword(object me)
{
        object sword;

        if(!present(me,environment()))
                return ;                
        if (!me->query("marks/zhu_8sword"))
        {
          message_vision( HIG "三日仿佛千年，在你等得焦头烂额，心急如焚之际。。。。
          朱停缓缓从内屋走了出来，双手捧上"HIC "『天剑』" HIG "，小心翼翼交给你手中。
          \n\n朱停冷冷道：若不是千年的岁月磨去了这天剑的血煞之气，一百个老朱的命赔进去也铸不成这把大凶之剑！
          朱停叹了口气道：拿去吧，自己好自为之！ \n"NOR,me);
        sword=new(__DIR__"obj/fixed_8sword");
        sword->move(me);   
        me->set("marks/zhu_8sword",1);   
        }               
        return ;
}




