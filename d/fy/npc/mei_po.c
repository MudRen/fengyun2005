// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("媒婆", ({ "mei po","po" }) );
    	set("title", "鸳鸯亭");
    	set("no_arrest",1);
    	set("gender", "女性" );
    	set("age", 43);
    	set("long", "一位精明能干的老媒婆。\n");
    	
    	set("combat_exp", 10000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"婚约" : 	"是啊... 这里就可以缔结和解除婚约",
        	"marry" : 	"是啊... 这里就可以缔结和解除婚约",
       		"离婚":		"是啊... 这里就可以缔结和解除婚约",
       		"divorce":	"是啊... 这里就可以缔结和解除婚约",
        	"desert":	"是啊... 这里就可以缔结和解除婚约",
        	"遗弃":		"是啊... 这里就可以缔结和解除婚约",
        ]) );
        
    	set_skill("dodge", 500);
    	set_skill("unarmed", 300);
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
}

void init()
{
    	add_action("do_marry", "marry");
    	add_action("do_unmarry", "divorce");
		add_action("do_desert","deserted");
}


int do_desert(string arg){
	
	object me;
	string name_c,file;
	object spouse,owner;
	int duration,flag;
	mixed info;
	
	seteuid(getuid());
	
	me = this_player();
	
    if (!stringp(name_c = me->query("marry")))
    	return notify_fail("你还未有婚约啊，捣什么乱！\n");

	if (!arg)
		return notify_fail("你要和谁离婚？\n");
		
	if (arg != name_c)
		return notify_fail("媒婆说：那不是你的另一半吧？\n");
		
	if (me->query("jiebai"))
		return notify_fail("媒婆说：你好象没有在这里结过婚吧。\n");
		
	if (objectp(spouse = find_player(name_c)))
		return notify_fail(spouse->name(1)+"不是在线上么？找就是了。\n");
		
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
		message_vision(CYN"媒婆叹了口气说，可怜的孩子，原来你已经是无人依靠了，我就帮帮你吧。\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)魂绝人世，与%s(%s)之婚约自动解除！", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
        me->add("divorced",1);
        me->delete("marry_name");
        return 1;
     }
	
	// 这个情况是 s-f 后又Login一个相同id的
	if (spouse->query("marry")!= me->query("id")
		 && spouse->query("marry_name")!= me->name(1)){
		 message_vision(CYN"媒婆叹了口气说，可怜的孩子，原来你的另一半已经不是原来的了，我就帮帮你吧。\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)魂绝人世，与%s(%s)之婚约自动解除！", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
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
		message_vision("媒婆说：啊呀，才过了"+ chinese_number(duration/86400)+"天你就熬不住啦，再等上"
		+ chinese_number(60 - duration/86400)+"天看看吧，说不定你的心上人还会回来的。\n",me);	
		destruct(spouse);
		destruct(owner);
		return 1;
	}
			
	message_vision("媒婆摇摇头说："+spouse->name()+"居然这么狠心丢下你不管，我就帮帮你吧。\n",me);
	CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)失踪多日，%s(%s)与其解除婚约，男再婚、女再嫁互不相干！！", 
                spouse->name(1),
                spouse->query("id"),
                me->name(1),
                me->query("id")));
	
	me->delete("marry");
    me->add("divorced",1);
    me->delete("marry_name");	
	
	spouse->delete("marry");
	spouse->add("divorced",1);
	spouse->delete("marry_name");
	
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
    string myclass,otherclass;
    me = this_player();
    if( me->query("marry"))
        write("你已经和别人有婚约了吧?这里不允许重婚的。\n");
    else if (me->query("jiebai"))
    	write("你已经和人结拜过了，请参看有关结婚和结拜的帮助文件。\n");
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("你想和谁缔结良缘？\n");
    else if( obj->query("marry"))
        write("你的对象已经和别人有婚约了吧?这里不允许重婚的。\n");
    else if (obj->query("jiebai"))
    	write("你的对象已经和人结拜过了，请参看有关结婚和结拜的帮助文件。\n");
    else if((int)me->query("age")<14 && (string)me->query("gender")=="男性" ||
            (int)me->query("age")<12 && (string)me->query("gender")=="女性")
        write("你太小啦，怎么可以啦？\n");  
    else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
            myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            (otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        write("出家人是不可以结婚的。\n"); 
    else if( !living(obj) )
        write(obj->name() + "已经无法和你缔结良缘了。\n");  
    else if(obj==me)
        write("你是自恋狂吗？\n");
    else if(!userp(obj))
        write("你只可和玩家结婚。\n");
    else if((string)obj->query("gender")== (string)me->query("gender")) {    	
    	ccommand("tong");
        write("断袖？这个似乎在风云里还行不通。\n");  
    } else if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
    {
        message_vision(MAG "\n$N对著$n说道：" 
                       + RANK_D->query_self(me) 
                       + me->name() + "，愿意和"
                       + RANK_D->query_respect(obj) + 
                       "结为夫妇\n\n"NOR, me,obj);           
        me->set_temp(obj->query("id") + "m",1);
        tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对" 
                    +me->name() + "("+(string)me->query("id")+
                    ")"+ "下一次 marry 指令。\n"NOR);
        write(MAG "现在你急切盼望着你的心上人说同意...\n"NOR);
    }
    else
    {
        me->set("marry",obj->query("id"));
        me->set("marry_name",obj->query("name"));
        obj->set("marry",me->query("id"));
        obj->set("marry_name",me->query("name"));
        obj->delete_temp(me->query("id")+"m");
        
        message_vision(MAG "恭喜 $N 和 $n ，一对璧人喜结良缘。\n"NOR,
                       obj, me);
        if(me->query("gender")=="男性")
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s(%s)和%s(%s)喜结良缘！", 
                me->name(1),me->query("id"), obj->name(1), obj->query("id")));
        else
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s(%s)和%s(%s)喜结良缘！", 
                obj->name(1), obj->query("id"),me->name(1),me->query("id")));
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
    if (!me->query("marry"))  write("你还未有婚约啊。\n");
    else if (me->query("jiebai"))	write("请到桃源亭去解除结义。\n");
    else if(!objectp(couple_ob =
                present(target=(string)me->query("marry"), environment(me))))
        write("你的伴侣现在不在场.\n");
    else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
    {
        message_vision(MAG "\n$N对著$n说道：" + RANK_D->query_self(me) 
                       + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                      NOR, me, couple_ob);           
        me->set_temp(couple_ob->query("id")+"d",1);
        tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                    + "下一次 divorce 指令。\n"NOR);
        write(MAG"现在你只有等着" +couple_ob->query("name")+"同意啦...\n"NOR);
    } else { 
        me->delete("marry");
        couple_ob->delete("marry");
        me->add("divorced",1);
        couple_ob->add("divorced",1);
        couple_ob->delete_temp(me->query("id")+"d");
        
        message_vision(MAG " $N 和 $n 从现在开始解除婚约，男再婚、女再嫁互不相干！\n"NOR,
                       couple_ob, me);
        if(me->query("gender")=="男性")
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)和%s(%s)解除婚约，男再婚、女再嫁互不相干！", me->name(1),
                me->query("id"),couple_ob->name(1),couple_ob->query("id")));
        else
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)和%s(%s)解除婚约，男再婚、女再嫁互不相干！",couple_ob->name(1),
                couple_ob->query("id"),me->name(1),me->query("id")));
    }
    return 1;
}

int do_register(string arg)
{
    object obj, me;
    object ob;
    int i;
    string myclass,otherclass;
    me = this_player();
    if( !me->query("marry"))
        write("你还没有婚约，要登记什么？\n");
       
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("你想和谁登记结婚记录？\n");
    /*else if(!objectp(obj =
                present(target=(string)me->query("marry"), environment(me))))
        write("你的伴侣现在不在场.\n");
    */

    else if( !me->query("id") == obj->query("marry"))
        write(obj->name()+"好像不是你的婚约配偶，你们想做什么？\n");
    else {
        me->set("marry_name",obj->query("name"));
        obj->set("marry_name",me->query("name"));
        message_vision(YEL" $N 和 $n 的婚约已经记录在案。\n"NOR,
                       obj, me);
    }
    return 1;
}