#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("郭大路", ({ "guo", "guo dalu" }) );
        set("long", "郭大路，大方的大，上路的路。人如其名，郭大路是个很大路的人。\n");
   		set("class","fugui");
        create_family("富贵山庄", 7, "庄主");
        set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({ "小懒虫","懒虫","大懒虫","小懒鬼","懒鬼","大懒鬼",
                "小懒侠","大懒侠","义士","义侠","枪豪","枪霸",CYN"枪王"NOR,
                CYN"枪神"NOR,CYN"九洲枪神"NOR,HIC"欢乐英雄"NOR}));
		set("attitude","friendly");
                   	
		set("chat_chance",1);
		set("chat_msg",	({
			"郭大路说道：“我这人难道是天生的穷命？就不能有天不挨饿的？
哎，现在连早上吃的鸭皮怕都已经消化得快差不多了。”\n",
			"郭大路说道：唉，离开富贵山庄这么久了，真想念庄子里的兄弟们，
和庄子里的那竹叶青啊！\n",
			
		})  );
        
        set("combat_exp", 4000000);
        
        set_skill("move", 150);
        set_skill("foreknowledge", 100);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("spear", 150);
        set_skill("chanting", 100);
        set_skill("perception",100);
        set_skill("force", 150);
		set_skill("unarmed", 150);
		set_skill("literate", 100);
        
        set_skill("skyforce",140);
        set_skill("xuezhan-spear",150);
        set_skill("hawk-steps",150);
        set_skill("eagle-claw",150);
        
        map_skill("force", "skyforce");
		map_skill("parry","xuezhan-spear");
		map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");  
	
		set("inquiry",	([
			"好酒":  "若有好酒，快快拿来给我！\n",
			"王动" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"林太平" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"燕七" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"鸭皮" : "麦老广这糟老头子的烧鸭实在不错，实在不错。\n",
			"烧鸭" : "麦老广这糟老头子的烧鸭实在不错，实在不错。\n",
			"wangdong" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"lintaiping" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"yanqin" : "他是我郭大路的好兄弟,可是我....唉，对不住他....\n",
			"kaoya" : "麦老广这糟老头子的烧鸭实在不错，实在不错。\n",
			"竹叶青":	"这可不是寻常小店里能买到的那种，是我王兄弟多年
的藏货，可惜他七藏八藏，连自己都不知道放哪儿去了。\n",
			]));
		setup();
        carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if( find_call_out("do_recruit") != -1 )
             command("say 慢著，一个一个来。");
        else
             call_out("do_recruit", 2, ob);
       
}

void do_recruit(object me)
{
		
		
		if( me->query("gender") != "男性" )       {
          	command("say 我只收男弟子，你还是另谋高就吧！");
          	return 0;
          }
          
        if(!me->query_temp("marks/烤鸭"))        {
        	command("say 我肚子空空如也，哪有什么心思收徒弟啊！");
        	return 0;
		  }
	  	
	  	if(!me->query_temp("marks/烂瓦罐"))  	{
	  		command("say 我嗓门冒火，哪有什么心思收徒弟啊！");
	  		return 0;
	  	}
	  	
	  	command("say 兄弟你可真大路啊，你帮我了却心头大事，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
	  
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "fugui");
}

int accept_object(object who, object ob)
{	
		object jinlian;
	
		if (ob->query("liquid/type")=="alcohol")
		{
			if (ob->query("liquid/remaining")< 50)
			{
				command("say 开玩笑吧，拿空的来骗我？");
				return 0;
			}

			if (ob->query("name")=="烂瓦罐") {
				write("郭大路拍碎烂瓦罐的泥盖，将酒倒入口中，眯缝着眼睛，面上露出陶
醉的神情。良久，郭大路长舒一口气：“人间极品，人间极品啊！”\n");
				who->set_temp("marks/烂瓦罐",1);
				return 1;
			}

		if (ob->query("name")==HIG"酒坛"NOR 
			&& ob->query("liquid/name")=="竹叶青") {
				
			if(ob->query("liquid/remaining")==1500 )
			{
				write("郭大路拍碎封坛的泥盖，闭着眼睛，深深吸了口气，叹道：“这不是
香气，简直是仙气啊。”\n");
				command("pat " + who->query("id"));
				write("郭大路大笑道：“兄弟比我郭大路还要上路啊。\n");
				
				if (who->query_skill("hawk-steps",1)>120)
				{
					write("郭大路说道：这条金链子麻烦你交给我大哥王动，
说郭大路现在想想还是回山庄的好，不仅有饭吃有酒
喝，还有他们几个好朋友，再赶我走我也不走了。\n");
	        		jinlian = new(__DIR__"obj/chain");
	        		jinlian->move(who);
	        		who->set_temp("marks/得到金链",1);
        		} else if (who->query("class")== "fugui")
        		{		
        			write("郭大路说：恩，你一边学功夫，一边要继续地，不断地给我送这样的好酒来！");
        		}    			
        		return 1;
       		}
			else 
			{
				write("郭大路顿时两眼放光，一饮而尽后，舔舔舌头晃晃脑袋说，这酒么，
好则好矣，可惜太少，不过瘾，不过瘾！\n");
			}
			return 1;
		}
				
		command("shake " + who->query("id"));
		command("say 这也叫酒吗？入口不醇，淡而无味，不过瘾，不过瘾，我要的是"YEL"好酒！\n"NOR);
		return 0;
				
		}
	
		if (ob->query("name")=="烤鸭")
		{ 
			who->set_temp("marks/烤鸭",1);
			write("郭大路一下窜了起来大叫道：“啊，麦老广的烧鸭，老兄真是上路啊。\n");
			return 1;
		}
	
		message_vision("$N扫了一眼$n手中的东西，懒懒的说，“吃这种东西，还不如饿死算了。”\n",this_object(),this_player());
		return 0;
}

