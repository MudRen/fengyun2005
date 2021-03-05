inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int do_attempt(string arg);

void create()	
{
        object weapon;
        
        set_name("司空掏星", ({ "sikong taoxing","sikong"}) );
        set("long","司空掏星是司空摘星的堂弟，自诩是天下第二神偷。\n");
        set("gender", "男性" );
    	set("env/wimpy",20);
		
		set("nickname", YEL"猿精"NOR);
        set("title",WHT"天下第二神偷"NOR);
		
        set("chat_chance", 1);
        set("chat_msg", ([
        	"天下第一神偷":	"虚其位以待之，我可不像摘星那么老脸皮。\n",
        	"天下第一":	"虚其位以待之，我可不像摘星那么老脸皮。\n",
        	"司空摘星":	"摘星有什么稀奇，要能掏心才是真本事！\n",
        	"司空":		"摘星有什么稀奇，要能掏心才是真本事！\n",
        	"掏心":		"。。。。。。。。。。\n",	
        	"神偷":		"天下号称神偷的很多，像我这么有真才实学的就很少了。\n",
        	"像我":		"你的脑后骨很像我，看来有神偷的潜力。\n",
        	"资质":		"你的脑后骨很像我，看来有神偷的潜力。\n",	
        ]) );

         set("inquiry",([
        ]) );

		set("age", 34);
        
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
    
        set_skill("perception", 200);
        set_skill("move", 400);
        set_skill("monkey-claw",200);
        set_skill("dodge", 200);
        set_skill("unarmed",200);
        set_skill("stealing",321);
        set_skill("betting",300);
        
        map_skill("unarmed", "monkey-claw");
              
        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(HIR BLK"破破烂烂沾满灰泥的臭衣衫"NOR, ({ "cloth" }) );
        weapon->set("long","破破烂烂沾满灰泥的臭衣衫(Cloth)。");
        weapon->set("value",0);
        weapon->wear();

}


void init()
{
        object ob;
        ::init();
        add_action("do_attempt","apprentice");

}


void smart_fight() {
	message_vision(CYN"\n司空掏星说：少陪了！嗖地一声，窜上屋梁消失了。\n"NOR,this_object());
	destruct(this_object());
}


int do_attempt(string arg)
{
        object ob;
        ob = this_player();
        
        if (!arg || arg!= "sikong" && arg!="sikong taoxing"){
        	tell_object(ob,"你想拜谁?\n");
        	return 1;
        }
        if (REWARD_D->check_m_success(ob,"神偷天下")) {
        	command("say 徒弟乖，师傅领进门，修行在自身。。。");
        	return 1;
        }
        
        if (REWARD_D->riddle_check(ob,"神偷天下")==2) {
        	command("say 你先得证明你自己的能耐才行。");
        	return 1;
        }
        	
        if (!REWARD_D->riddle_check(ob,"神偷天下") || !ob->query_temp("marks/wanma/app_sikong")) {
        	message_vision("司空掏星一本正经板着脸说：你这点资质，怎么能做我徒弟呢？\n\n",ob);
        	ob->set_temp("marks/wanma/app_sikong",1);
        } else if (ob->query_temp("marks/wanma/app_sikong")==1) {
        	message_vision("司空掏星说：不行不行，随便收人做徒弟，天下不就到处是神偷了？\n",ob);
        	ob->set_temp("marks/wanma/app_sikong",2);
        } else {
        	message_vision("司空掏星咪咪笑着说：既然你再三求之，我就勉强答应了。\n\n",ob);
        	command("say 不过，想做我徒弟，我得先考考你。");
        	REWARD_D->riddle_set(ob,"神偷天下",2);
        	command("say 我这次到藏北来，是因为，呃，想上几炷香。");
        	command("say 没想到这儿几个寺庙里的喇嘛对我很不礼貌、很不礼貌，老是派人盯着我。");
        	command("say 所以我一气之下，就在其中几个庙里借了三样东西，不过，他们盯得太紧，所以带不出来。");
        	command("say 你如果能把这三样东西都找来给我，我就收你做徒弟了。");
        }
        	
        return 1;
}

                        
int prevent_learn(object me, string skill)
{
      command("emote 一脸惊吓的看着你说：这个教你了，岂不就有了两个司空掏星？");
      command("emote 把头摇得像拨浪鼓似的：不行，不行。");
      return 1;
}


int accept_object(object me, object obj)
{
		string *material_names=({ "法杖","牙齿","塔公寺地契" });
		string ob_name;
		int success, makeup_ok,i;
		object book;
		
		
		if (!REWARD_D->riddle_check(me,"神偷天下")) {
			command("say 我司空掏星什么东西搞不到？哪儿用的着你来孝敬。");
			return 0;
		}
		
		ob_name= obj->query("name");
		success=1;
		makeup_ok=0;
		for(i=0;i<3;i++)
		{
			if(ob_name==material_names[i])
			{
				if(me->query_temp("marks/wanma/sikong/"+ob_name))
				{
					command("say 这东西你不是给过我了，难道原来那个是假的？”\n");
					return 0;
				}
				me->set_temp("marks/wanma/sikong/"+ob_name,1);
				command("say 好，不错不错，此物我且收下。");
				makeup_ok=1;
			}
			success=success*me->query_temp("marks/wanma/sikong/"+material_names[i]);
		}
		if(!success) return makeup_ok; 
			
		me->delete_temp("marks/wanma/sikong");	
		
		tell_object(me,CYN"司空掏星说：啊呀呀，你竟然都找到了，很好、很好。
司空掏星扳起手指数了数说：自我出关以来，你已经是我的第二百四十七个徒弟了。\n"NOR);
		tell_object(me,CYN"司空掏星说：师傅很忙，要教很多徒弟，给你本书你自己去修炼吧。\n"NOR);
		book = new(BOOKS"foreknowledge_75");
		book->move(me);
		message_vision(CYN"\n司空掏星说：少陪了！嗖地一声，窜上屋梁消失了。\n"NOR,this_object());
		REWARD_D->riddle_done(me,"神偷天下",50,1);       
        return 1;
}
