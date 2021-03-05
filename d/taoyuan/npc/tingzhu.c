// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("桃源亭主", ({ "taoyuan tingzhu","tingzhu" }) );
    	set("title", HIR"桃源三结义 契若金兰情"NOR);
    	set("no_arrest",1);
    	set("gender", "男性" );
    	set("age", 143);
    	set("long", "一位长须尽白的老者，慈眉善目，微笑地看着你。\n");
    	set("combat_exp", 10000000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"结义" : 	"昔日桃源结义，豪情千古，素为老夫仰慕，若能见证世人有此侠情美事，不亦快哉。",
        	"jieyi" : 	"昔日桃源结义，豪情千古，素为老夫仰慕，若能见证世人有此侠情美事，不亦快哉。",
       		"绝交":		"唉，兄弟情深，姐妹难求，汝等可要三思而行啊，割袍断义之举，若非是无可挽回，还是斟酌再三为妙。",
        	"juejiao":	"唉，兄弟情深，姐妹难求，汝等可要三思而行啊，割袍断义之举，若非是无可挽回，还是斟酌再三为妙。",
       	]) );
        
    	set_skill("dodge", 500);
    	set_skill("unarmed", 300);
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();
}


void init()
{
    	add_action("do_marry", ({"jieyi", "jiebai"}) );
    	add_action("do_unmarry", "juejiao");	
    	add_action("do_desert", "betray");	
}


int do_desert(string arg){
	
	object me;
	string name_c,file;
	object spouse,owner;
	int duration,flag;
	mixed info;
	
	seteuid(getuid());
	
	me = this_player();
	
    if (!stringp(name_c = me->query("jiebai")))
    	return notify_fail("你没和人结拜啊，捣什么乱！\n");

	if (!arg)
		return notify_fail("你要和谁绝交？\n");
		
	if (arg != name_c)
		return notify_fail("桃源亭主说：那不是你的结拜兄弟姐妹吧？\n");
		
	if (objectp(spouse = find_player(name_c)))
		return notify_fail(spouse->name(1)+"不是在线上么？直接找他了断就是了。\n");
		
	owner = FINGER_D->acquire_login_ob(name_c);
	
	flag = 1;
	
	if (!owner) flag = 0;
	else {
		spouse = LOGIN_D->make_body(owner);		
		if (!spouse) flag = 0;
		else if (!spouse->restore())	flag = 0;
	}
	
	// Purged or suicided. 只需要对自己做处理。
	if (!flag) {
		message_vision(CYN"桃源亭主叹了口气说：可怜的孩子，人鬼相隔，情何以伤，老夫就帮帮你吧。\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)魂绝人世，与%s(%s)之结拜自动解除！", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
		me->delete("jiebai");
        me->add("divorced",1);
        me->delete("marry_name");
        return 1;
     }
	
	// 这个情况是 s-f 后又Login一个相同id的
	if (spouse->query("marry")!= me->query("id")
		 && spouse->query("marry_name")!= me->name(1)){
		 message_vision(CYN"桃源亭主叹了口气说：可怜的孩子，世事无常，昔日兄妹既已杳杳无踪，老夫就帮帮你吧。\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)杳然无踪，已非今日之人，与%s(%s)之结拜自动解除！", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
		me->delete("jiebai");
        me->add("divorced",1);
        me->delete("marry_name");
        destruct(owner);
        destruct(spouse);
        return 1;
    }			 	
		
	file = DATA_DIR + "login/" + name_c[0..0] + "/" + name_c +"/" +  name_c + SAVE_EXTENSION;

//	tell_object(me,"file is "+ file);
	
	info = stat(file);
	duration = time()- info[1];
	
	if (duration<0){
		tell_object(me,"目前系统时间紊乱，此命令不能执行。\n");
		destruct(spouse);
		destruct(owner);
		return 1;
	}

//	if (duration < 10) {	
	if (duration < 5184000) {
		message_vision("桃源亭主嘿然道：昔日桃源三结义，生死为契，何等忠义，而你才过了"+ chinese_number(duration/86400)+"天就有二心，岂能善终？
再等上"+ chinese_number(60 - duration/86400)+"天看看吧，说不定你的义兄义妹还会回来的。\n",me);	
		destruct(spouse);
		destruct(owner);
		return 1;
	}
			
	message_vision("桃源亭主摇摇头说："+spouse->name()+"既然情薄如此，撒手而去，那老夫就帮帮你吧。\n",me);
	CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)失踪多日，%s(%s)与其解除金兰契约，二人再无相干！！", 
                spouse->name(1),
                spouse->query("id"),
                me->name(1),
                me->query("id")));
	
	me->delete("marry");
    me->add("divorced",1);
    me->delete("marry_name");
    me->delete("jiebai");	
	
	spouse->delete("marry");
	spouse->add("divorced",1);
	spouse->delete("marry_name");
	spouse->delete("jiebai");
	me->save();
	spouse->save();
	
	destruct(owner);
	destruct(spouse);
	
	return 1;	
}


int do_marry(string arg) //there is a marry emote, ruined all the messages.
{
    object obj, me;
    object ob;
    int i;
    string myclass,otherclass,word1;
    string myname, hisname;
    me = this_player();
    
    if (!arg){
    	write("你要和谁结拜？\n");
    	return 1;
    }
    	
    if( me->query("marry") || me->query("jiebai"))
        write("你已经和别人有约了吧？不要再三心二意了。\n");
        
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("你想和谁结拜？\n");
        
    else if (obj->query("jiebai"))
    	write("对方已经与他人结拜过了。\n");
              
    else if( obj->query("marry"))
        write("你的对象已经心有他属了。\n");
        
    else if((int)me->query("age")<14 && (string)me->query("gender")=="男性" ||
            (int)me->query("age")<12 && (string)me->query("gender")=="女性")
        write("你年龄太小，哪儿懂得结拜的含义呢（男〉14、女〉12）。\n");  

/*    else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
            myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            (otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        write("出家人是不可以结婚。\n"); */
    else if( !living(obj) )
        write(obj->name() + "已经无法和你结拜。\n");  
        
    else if(obj==me)
        write("你是自恋狂吗？\n");
        
    else if(!userp(obj))
        write("你只可和玩家结拜。\n");
/*   else if((string)obj->query("gender")== (string)me->query("gender")) {    	
    	ccommand("tong");
        write("断袖？这个似乎在风云里还行不通。\n");  
    }*/ 
    else if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
    {
        myname = me->name(1);
        hisname = obj->name(1);
        
        if (me->query("gender")=="男性" && obj->query("gender")=="男性") 
        	word1 = "兄弟";
        else if (me->query("gender") == "女性" && obj->query("gender") == "女性")
        	word1 = "姐妹";
        else {
        	if (me->query("mud_age") < obj->query("mud_age"))
        		word1 = "姐弟";
        	else
	        		word1 = "兄妹";
        }        	
        
        message_vision(CYN"$N对桃源亭主深深一躬，郑重道：我"+ myname+"与"+ hisname +"相识以来，甚是投缘，情若"+word1+"，
欲义结金兰，从此"+word1+"相称，可请老丈做个证人？\n"NOR,me);       
        me->set_temp(obj->query("id") + "j",1);
        tell_object(obj, "桃源亭主微微一笑，朝你问道："+myname+"欲和你义结金兰，成为异性"+word1+"，你意下如何？
如果你愿意，请你也对"+myname+"("+(string)me->query("id")+")"+ "下一次 jieyi 指令。\n");        
    }
    else
    {
        me->set("marry",obj->query("id"));
        me->set("marry_name",obj->query("name"));
        me->set("jiebai",obj->query("id"));
        obj->delete_temp(me->query("id")+"j");
        
        obj->set("jiebai",me->query("id"));
        obj->set("marry",me->query("id"));
        obj->set("marry_name",me->query("name"));
        message_vision(HIC"桃源亭主向二人颔了颔首，神色肃然，摆出刘关张三义塑像，拜了三拜，口中喃喃有词，
然后转身示意二人叩拜结义。\n"NOR,obj, me);
        
        message_vision(HIC"\n当下"+me->name(1)+"和"+ obj->name(1)+"撮土为香，歃血为盟，结为八拜之交。。\n\n"NOR,obj, me);
        CHANNEL_D->do_sys_channel("info",sprintf(
                "%s(%s)和%s(%s)于%s在桃源亭义结金兰！", 
                me->name(1),me->query("id"), obj->name(1), obj->query("id"),
                NATURE_D->game_time()));
    }
    return 1;
}

int do_unmarry(string arg)
{
    object marry_card1,marry_card2,  me;
    object couple_ob;
    int i, have_marry;
    string target, tmpstr1, tmpstr2,str1,str2;
    string cardname;
             
    me = this_player();       
    if (!me->query("jiebai"))  write("你未曾与人结拜。\n");
    else if(!objectp(couple_ob =
                present(target=(string)me->query("jiebai"), environment(me))))
        write("你的结拜兄弟/姐妹不在这儿。\n");
        
    else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"dj"))
    {
        message_vision(WHT "\n$N“嘶”的一声，将长袍前襟撕下，对$n说道：你我今天已恩断义绝，就此了断了吧！\n\n"NOR, me, couple_ob);           
        me->set_temp(couple_ob->query("id")+"dj",1);
        tell_object(couple_ob,  "如果你愿意与对方绝交，请你也" + "下一次 juejiao 指令。\n"NOR);        
    } else { 
        me->delete("marry");
        me->delete("jiebai");
        couple_ob->delete("marry");
        couple_ob->delete("jiebai");
        couple_ob->delete_temp(me->query("id")+"dj");
        me->add("divorced",1);
        couple_ob->add("divorced",1);
        message_vision(WHT " $N 和 $n 割袍断义，从此互不相干！\n\n"NOR,couple_ob, me);
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)和%s(%s)割袍断义，从此各奔东西，互不相干！",couple_ob->name(1),
                couple_ob->query("id"),me->name(1),me->query("id")));
    }
    return 1;
}
