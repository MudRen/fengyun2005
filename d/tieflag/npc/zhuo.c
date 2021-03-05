// zhuo.c
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("卓三娘", ({"zhuo"}) );
        set("gender", "女性" );
        set("nickname", "闪电");
        set("age", 36);
        set("agi",30);
        set("no_arrest",1);
        set("per", 30);
        set("long","闪电卓三娘轻功举世无双，在碧落赋中排名第三。\n"	);
        
        set("combat_exp", 1100000);
        set("score", 10000);
    
        set_skill("move", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        
    	set_skill("meihua-shou", 150);
    	set_skill("qidaoforce", 150);
    	set_skill("feixian-steps", 120);

     	map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "feixian-steps");
        map_skill("move", "feixian-steps");
        
        set("chat_chance",1);
        set("chat_msg",({
        	"卓三娘说道：“风老四要不是练功走火，我们怎么会怕那穿嫁衣之人！”\n",
        	"卓三娘说道：“如果你能帮助我们，我们就可以得到夜帝的宝藏，和神功宝典！”\n",
        	}) );
		setup();
        carry_object("/obj/armor/cloth")->wear();  
}

void init()
{
    	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) {
	        remove_call_out("greeting");
	        remove_call_out("feng_revive");
	        if (REWARD_D->riddle_check(me, "嫁衣明玉")== 1
	        	|| me->query_temp("marks/嫁衣"))	    
	        {
	        	command("say 不知死活的东西，看"+RANK_D->query_self_rude(this_object())+"教训教训你！");
	        	this_object()->kill_ob(me);   
	            return;
	        }
		    call_out("greeting", 1, me);
	        add_action("do_accept","accept");
	        return;
        }
}

void greeting(object me)
{
		object feng;
    	if (feng=(present("feng jiuyou",environment()) )  )
    	if (base_name(feng)==__DIR__"feng" )
       		command("say 我们来到这里本想取得夜帝的宝藏，没想到风老四忽然走火入魔，
你如果愿意帮助我们，夜帝的宝藏就是你的了。(accept yes/accept no)\n");
          	
}

int do_accept(string arg)
{
	object feng;
    object me;
	if (!arg || (arg!= "yes" && arg !="no")) return 0;
    me=this_player();
    if (me->is_fighting()) return 0;
    if (arg=="yes")
    {
    	if (!feng=(present("feng jiuyou",environment()) )  ) 
    	{
    		command("sigh");
			command("say 没有风老四，你想帮我们也是白搭。");
	    	return 1;
		}
		if (base_name(feng)!=__DIR__"feng" )
		{
			command("grin");
			command("say 风老四已经醒了，我们还要你帮干嘛？\n");
			return 1;
		}	
    	message_vision( YEL "$N将手贴在$n的后心，助他收摄心神！\n"NOR,me,feng);
    	me->start_busy(4);
		if (me->query("force")<200)
		{
			tell_object(me,"可是你的内力不够耶。\n");
			return 1;			
		}
		message_vision(CYN"$N笑道：你如此好心，我就告诉你个秘密吧。\n"NOR, me);
        tell_object(me,CYN"卓三娘悄悄地对你说：西边的恶人谷下面有个大宝藏。。\n"NOR);
        message_vision(CYN"卓三娘挤了挤眼睛：不过，凤老四不一定愿意放你走哦。\n"NOR, me);
        me->set("force",0);
        REWARD_D->riddle_set( me,"嫁衣明玉", 2);
        call_out("feng_revive",5,me,feng);
    }
    else
    {
      	command("say 不知死活的东西，看老娘教训教训你！");
      	this_object()->kill_ob(me);
      	me->kill_ob(this_object());
      	if (!feng=(present("feng jiuyou",environment()) )  ) 
    		 	return 1;
	  	if (base_name(feng)!=__DIR__"feng" )
		{
			feng->kill_ob(me);
			me->kill_ob(feng);
			return 1;
		}
		me->set_temp("marks/嫁衣",1);	
	    call_out("feng_revive",20,me,feng);
    } 
    return 1;                                          
}


void feng_revive(object me,object feng)
{
	object lishi;
	object ark;
	object woman;
	int damage;    
    string myfile;
    myfile=base_name(this_object());
    //I do not want to specify an abs name of a room
    myfile=replace_string(myfile,"npc/zhuo","ark");
	if (environment(me)!=environment(this_object())) return;
	if (!feng)	return;
	if (!living(feng)) return;
	destruct(feng);
	feng=new(__DIR__"feng2");
	feng->move(environment());
	message_vision(YEL"\n\n$N长吸了一口气，站了起来！\n"NOR,feng);
	message_vision(YEL"$N喝道：“神斧力士何在！”\n\n"NOR,feng);
	lishi=new(__DIR__"lishi");
	lishi->move(environment()); 
	message_vision(WHT"\n一个古铜色的大汉出现在$N的面前。\n\n",feng);
	if (!objectp(ark=find_object(myfile)))
    	ark=load_object(myfile);
	if (!me->query_temp("marks/嫁衣"))
	{
    	message_vision(YEL"$n说道：让力士来助你一臂之力吧！\n"NOR,me,feng);
    	message_vision(YEL"$n大喝一声，一把抓住$N的衣领，将$N向方舟丢去！\n\n"NOR,me,lishi);
    	me->move(ark);
    }
    else
    {
    	message_vision(YEL"$N大喝一声：“敢管咱家的闲事，当真活得不耐烦了！”\n"NOR,feng);	
    	feng->kill_ob(me);
    	lishi->kill_ob(me);
    	message_vision( HIR "\n神斧力士忽然奋起一拳，击在$N的胸膛上。\n"NOR,me);
    	damage=500+random(750);
        me->receive_damage("kee",damage,lishi);
        COMBAT_D->report_status(me);
        message_vision( HIR "$N的身子被打得象断线的风筝一样飞入黑色的垂帘，久久才听见落地之声。\n\n"NOR,me);
        me->move(ark);
        if((woman=present("old woman",ark)) && me->query("kee")>0 )
        {
        	me->unconcious();
        	call_out("me_revive",9,me,woman);
        }
    }
    return;
}       

 
void me_revive(object me,object woman)
{                                                                      
		me->delete_temp("marks/嫁衣");
		if (REWARD_D->riddle_check(me,"嫁衣明玉"))	return;
		
		me->revive();
		if (environment(me)!=environment(woman)) return;
	
		message_vision(CYN"\n$N叹道：“可怜的孩子，你的所作所为我都知道了。”\n"NOR,woman);
		message_vision(CYN"$N说道：“你一心维护于我，我本该帮帮你，可是现在。。
我就告诉你一个秘密吧。
武林中有两大奇功：嫁衣神功和明玉功，非有缘者不能得之。
孩子，你好自为之，终有一天你会遇到这样的机缘的。\n\n"NOR, woman);
		REWARD_D->riddle_set(me,"嫁衣明玉", 1);
		
		return;
}
