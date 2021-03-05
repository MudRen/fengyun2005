inherit SMART_NPC;
#include <ansi.h>

int leave();
int annie_new_by();

void create()
{
    set_name("花茵" , ({ "hua yin","hua" }) );
    set("nickname",HIR"坐花茵"NOR);
    set("long", "这少女白色衣裙，衣袂飘飘，雅丽如仙，赤着宛如白玉般的双足在满地花茵上\n翩翩起舞。\n");
    set("attitude", "friendly");
    set("per",60);
    set("age", 29);
    set("gender", "女性" );
    create_family("白云城",1, "才女");
    set("combat_exp", 2200000);
    set("chat_chance", 2);
    set("chat_msg", ({
	"花茵赤着白玉般的双足，懒懒得斜靠在花茵中，灵巧的大眼睛偷偷地打量着你。\n",
	"花茵痴痴自语道：明日便是剑胆师兄的生辰，该"YEL"画"NOR"幅什么送给剑胆师兄呢？\n",
      }) );
    set("inquiry",  ([
	"画": (: annie_new_by :),
	"painting": (: annie_new_by :),	
	"救治剑胆" :  (: leave :),
      ]) );
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) ); 		
    
    auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);
    set_skill("spring-water",50);
    set_skill("iron-cloth",50);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
}

int annie_new_by()
{
    object me = this_player();
    
    if (me->query("combat_exp")<3100000) {
	tell_object( me, CYN"花茵叹道：哎呀，到底画什么好呢？总不成画你这么个不成器的家伙吧？\n"NOR);
	ccommand("sigh");
	tell_object( me, CYN"花茵心不在焉的看着你，说道：画艺武道本是一家，你武艺也不过勉勉强强，作画？还是免了吧？\n"NOR);
	tell_object( me, WHT"经验等级不够高（70），小姑娘不想理你。\n"NOR);
	// snicker
	return 1;
    }	
    
    if (REWARD_D->riddle_check(me,"王图一梦") != 1 )
    {
	tell_object( me, CYN"花茵叹道：哎呀，到底画什么好呢？总不成画你这么个不成器的家伙吧？\n"NOR);
	tell_object( me, CYN"花茵又仔细盯着你瞧了瞧，说道：\n"NOR);
	tell_object( me, CYN"不过，看你这不服输的样子，也许，将来真的会有所作为呢。\n"NOR);
	tell_object( me, "\n");
	tell_object( me, CYN"花茵指了指北边，又道：听说风云城的小吃摊老板娘是位隐居的高手，\n"NOR);
	tell_object( me, CYN"能在她手下平安吃碗面的，武艺都不会太低，江湖上很多后辈，\n都以吃面作为自身武艺的检验，当然，吃面的人总是远远多于吃完面的。\n"NOR);
	ccommand("say 你要不要也去试试？");
	ccommand("say 假若有日，你能名扬江湖，也别忘记小女子，闲暇时刻，来白云岛逛逛。");
	ccommand("say 小女子定当陪你游览这白云岛的山山水水，带你去听琴心妹妹的那绝世广陵。");
	ccommand("wink");
	ccommand("say 现在，我要继续想给师兄画什么了，你自己四处转转吧，小心别打扰了师傅。");
	// tell_object( me, "ＯＯＰＳ，有什么事儿没干。\n");
	// snicker
	return 1;
    }
    ccommand("emote 忽地笑道：剑胆师兄的生辰，花茵定要画一幅最好的自画像送给他，
这个呆头鹅，难道非要给他暗示才能。。。。？

花茵掰着玉葱一般的纤纤十指喃喃道：不过要画这幅“花间舞剑图”还须四样东西才行。
义海兄的兰竹笔，望仙乡三仙子的蝉衣笺，三朱三绿三青粉，和歙砚。你能帮我借来一用么？");
	REWARD_D->riddle_set(me,"王图一梦",2);
	return 1;
}

string *material_names=({
    "兰竹笔","蝉衣笺","三朱三绿三青粉","和歙砚"
        });

int accept_object(object me, object ob)
{
        string ob_name;
        int i,success,makeup_ok;
        
        ob_name=ob->query("name");
        success=1;
        makeup_ok=0;

		if (REWARD_D->riddle_check(me,"王图一梦") != 2 
			&& REWARD_D->riddle_check(me,"王图一梦") != 3)
		{
			ccommand("emote 甜笑道：多谢相赠，此物当可解我长夜寂寞。");
			return 1;
		}
		if (REWARD_D->riddle_check(me,"王图一梦") == 3 && me->query_temp("annie_by_1_2_4"))
		{
			ccommand("emote 疑惑道：你还不帮我把画送去么？");
			return 0;
		}

        for(i=0;i<4;i++)
        {
                if(ob_name==material_names[i])
                {
                        if(me->query_temp("annie/by_hy/"+ob_name))
                        {
                                message_vision("花茵宛然一笑，说道：“这个材料已经有了呢。”\n",me);
                                return 0;
                        }
                        me->set_temp("annie/by_hy/"+ob_name,1);
                        message_vision("花茵宛然一笑，说道：“多谢这位"+RANK_D->query_respect(me)+"为我找来"+ob_name+"。”\n",me);
                        makeup_ok=1;
                }
                success=success*me->query_temp("annie/by_hy/"+material_names[i]);
        }
        if(!success) return makeup_ok; 
        message_vision("花茵微微一笑，颔首致谢，铺开蝉衣笺纸，研墨提笔，心无旁笃地做起画来。。。\n",me);
        me->delete_temp("annie/by_hy");
        message_vision("片刻之後，花茵提笔收墨，对$N甜甜笑道：就有劳您送给我师兄剑胆，好么？\n",me);
        ob = new(__DIR__"obj/painting");
        ob->move(me);
		me->set_temp("annie_by_1_2_4",1);
        message_vision("花茵递给$N一卷花间舞剑图。\n",me);
		REWARD_D->riddle_set(me,"王图一梦",3);
        return 1;
}


int leave()
{
    
    object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"王图一梦");
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	if (is_fighting())
	{
		tell_object(this_player(),name()+"正忙，顾不上与你搭话。\n");
		return 1;
	}	
			
	if (environment() == room)
		return 0;
 	delete("chat_msg");
    message_vision(WHT"$N闻讯花容惨变，不及收拾手中笔墨，不发一言，匆匆赶往龙台。\n"NOR, this_object());
    move(room);
    return 1;
}

void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
}

void greeting(object ob)
{
        object corpse;
        if( !ob || environment(ob) != environment() ) return;

		if (REWARD_D->riddle_check(ob,"王图一梦") ==6 )
        {
                if (present("song shi",environment()) && present("jian dan",environment()) && present("qin xin",environment()) )
                {
                        present("jian dan",environment())->die();
                        corpse=present("corpse",environment());
                        if (corpse)
                                destruct(corpse);
                        message_vision(YEL"
花茵似乎根本没看到你的到来，伏在剑胆身上，兀自放声痛哭。

松实看了看你，双眼血红，悲声道：四师弟去了。

琴心愣愣着看着剑胆的尸身，过了半天，喃喃道：傻瓜，难道你真以为我什么都不知道么？
只是．．只是我．．琴心清澈有如龙台泉水的眼睛中终于滴下了一滴泪水。

泪滴在宁静的潭中，溅起一圈涟漪，散开．．隐去。
琴心深深地看了$N一眼，微微一福：多谢．．．此后当有用我之时烦请相告，琴心在所不辞。"WHT"

三人抱着剑胆的尸身消失在氤氲缭绕的白云之中。\n"NOR,ob);
                        ob->set("free_learn/by_magic",1);
                        destruct(present("song shi",environment()));
                        destruct(present("qin xin",environment()));
                        move(load_object("/obj/void"));
						REWARD_D->riddle_set(ob,"王图一梦",7);
						REWARD_D->riddle_done(ob,"白云五仙",20,1);
						tell_object(ob,YEL"你忽然很想去见一见叶孤城，看究竟是怎样的人能设下如此毒计。\n"NOR);
						die();
                }
                return;
        }

        if (present("song shi",environment()) && present("jian dan",environment()) && present("qin xin",environment()) && REWARD_D->riddle_check(ob,"王图一梦") ==4)
        {
                message_vision(YEL"花茵花容失色，扑在剑胆怀中兀自抽泣。
松实拿着酒葫芦，取出银针插了进去，半晌后，神色大变。
琴心把了许久剑胆的脉搏，忧道：这脉搏若有若无，时断时续，
看来。。要去请医仙叶星士速来。\n",ob);
                message_vision("
琴心望了身边几人，看看$N，愁眉道：我兄妹三人还须留下照看剑胆，
您可否速去紫气东来楼，请叶先生前来。\n"NOR,ob);
				REWARD_D->riddle_set(ob,"王图一梦",5);
        }
			

        return;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

