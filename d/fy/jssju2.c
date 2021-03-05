#include <ansi.h>
inherit ROOM;

string 	*ebook = ({" "});
string show_list();
int read_book(string arg);

// 	暂时还需要改动code来增加书籍

string *book_bai = explode(read_file("/doc/help/book/book_bai"), "Page");

void create()
{
    set("short", "三楼");
    set("long", @LONG
三楼是警世书局收藏、装订书籍的地方，不大的屋子里一排放着几张长九尺宽
五尺的[37m白木桌[32m，每张桌子前都有两三个伙计在忙碌。一旁的书柜上堆积如山的是刚
装订好还未上市的书籍，犹自散发着淡淡的油墨清香。
LONG
    );
    set("exits", ([
	"down" : __DIR__"jssju1",
	"up": __DIR__"jssju3",
      ]));

    set("item_desc", ([
		"白木桌": (: show_list() :),
		"书柜":	(: show_list() :),
		"shelf": (: show_list() :),
		"table": (: show_list() :),
    ]));

    set("objects", ([
	
    ]) );
	
    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",20);
    set("map","fynorth");
    setup();
}


string	show_list()	{
    write("这儿一排放着许多最新出版的线装书籍，用list可以查看目录：    
如果你想看的话，可以用read命令，read 1，就是阅读第一本。\n");
	return "";
}

void 	init(){
	add_action("do_read","read");
	add_action("do_list", "list");
}


string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,
	HIB "初窥门径" NOR,
	HIB "略知一二" NOR,
	HIB "马马虎虎" NOR,
	HIB "已有小成" NOR,
	CYN "心领神会" NOR,
	CYN "了然於胸" NOR,
	CYN "豁然贯通" NOR,
	HIC "举世无双" NOR,
	HIC "震古铄今" NOR,
	HIW "深不可测" NOR
});

string skill_level(int level)
{
	int grade;

	grade = level / 10;

	if( grade >= sizeof(knowledge_level_desc) )
		grade = sizeof(knowledge_level_desc)-1;
	return knowledge_level_desc[grade];

}

int	do_read(string arg){
	mapping *data;
	mapping tianjiao;
	string msg,*list,file;
	int i, j, num;
	
	if (this_player()->query_temp("timer/read_book")+1>time())
	{
		tell_object(this_player(),"慢慢来，一本一本读。\n");
		return 1;
	}
	this_player()->set_temp("timer/read_book",time());
	
	if (arg == "1"){
		data = STATUS_D->query_exp_list();
		num = sizeof(data);
		msg = HIR"	风云高手排行榜前"+ chinese_number(num)+"名\n"NOR;
		msg += CYN"=========================================\n"NOR;
		msg += sprintf("%-12s%-12s%-12s\n",
			"英文名","中文名","门派");
		msg += CYN"=========================================\n"NOR;
		for(i=0;i<num;i++)
		msg += sprintf("%-12s%-12s%-12s\n",
				data[i]["id"],
				data[i]["name"],
				F_MASTER->query_chinese_class(data[i]["class"]));
		msg += CYN"=========================================\n"NOR;
		tell_object(this_player(), msg);
		return 1;
	}
	
	if (arg == "2"){
		data = STATUS_D->query_riddle_list();
		num = sizeof(data);
		msg = HIR"	风云智多星排行榜前"+ chinese_number(num)+"名\n"NOR;
		msg += CYN"============================================\n"NOR;
		msg += sprintf("%-12s%-12s%-12s%-12s\n",
			"英文名","中文名","门派", "解密数");
		msg += CYN"============================================\n"NOR;
		for(i=0;i<num;i++)
		msg += sprintf("%-12s%-12s%-12s%-12s\n",
				data[i]["id"],
				data[i]["name"],
				F_MASTER->query_chinese_class(data[i]["class"]),
				skill_level(data[i]["r_num"]));
		msg += CYN"============================================\n"NOR;
		tell_object(this_player(), msg);
		return 1;
	}
	
	if (arg == "3") {
		tianjiao = this_player()->query("m_killer");
		tell_object(this_player(),WHT"\t　　		风云天骄录（"+ this_player()->name(1)+ "）\n"NOR);
    	write(HIR BLK"───────────────────────────────────────\n"NOR);
    	if (!tianjiao)	write (HIR "无\n"NOR);
    	else
    	{
			list = keys(tianjiao);
			i = 0;					// deal with the problem of setting riddle=0
			for(j=0; j<sizeof(list); j++)
			{
			    if (tianjiao[list[j]])
			 	{
			    	if(i%5!=4) 
						write(sprintf(YEL"%-16s"NOR,list[j]));
			    	else 
						write(YEL + list[j] + "\n"NOR);   
					i++;
				}
			}
    	}
		write(HIR BLK"\n───────────────────────────────────────\n"NOR);
		return 1;
	}

	if (arg == "4"){
		file = "/doc/help/book/book_bai";
		read_book(file);
		return 1;
	}
	
	if (!arg)
		return notify_fail("你要读那一本编号的书籍？\n");
	
	tell_object(this_player(),"这儿暂时没有这个编号的书籍。\n");	
	return 1;
}
	
	
int	do_list(){
	write(CYN"这儿的书记载着当前风云里的大事。
"WHT"	
	１。风云高手榜
	
	２。风云智多星榜
	
	３。风云天骄录（私有）
	
	４。百晓生奇门异术榜

"CYN"
你可以用ｒｅａｄ后面跟数字来阅读相对应的书籍。

	\n"NOR);
	return 1;
}

int read_book(string file)
{
        int i;
        string map, *search;
        object ob;
        ob = this_player();
	
		if (ob->query_temp("timer/help_list")+1 > time())
			return notify_fail("帮助系统正在恢复中，请在一秒后使用。\n");
		
		ob->set_temp("timer/help_list",time());
	
		write(CLR);

		write(read_file(file+"_main"));		// Show the table		
		input_to("selete_main",ob,file);
		return 1;
}

void back_off(string num, object ob, string file)
{
		write(CLR);
        write(read_file(file+"_main"));
        input_to("selete_main", ob, file);
}

void quit_help(object ob)
{
     	write(HIC"\n 谢谢使用风云书籍阅读系统！\n\n"NOR);
        return;
}


string page(string book, int page){

	 string *title;
	 	 	 	 
	 switch (book){
	 	case "bai":	title = book_bai; break;
		default: 	return "\\n\n没有这本书\n";
	 }
	 
	 if (page> sizeof(title))
	 	return " \n\n此页不存在，当前书籍共有"+sizeof(title)+"页，请按任意键返回目录。\n";
	 
	 return title[page-1];
}

void selete_main (string num, object ob, string file)
{        
        int number, total;
        string type, *data;
        string book;
               
	    if (ob->query_temp("timer/help_list")+2 > time())
        {
        	ob->add_temp("marks/repeat_help",1);
//        	CHANNEL_D->do_sys_channel(
//				"info",sprintf("%d",ob->query_temp("marks/repeat_help")));
        }	else
        	ob->delete_temp("marks/repeat_help");   
        
        if (ob->query_temp("marks/repeat_help")<4) {
	        ob->set_temp("timer/help_list",time()); 
	        
	        if (sscanf(num,"%d",number)== 1) {
	        	sscanf(file, "/doc/help/book/book_%s", book);
			}
	        if (book) {
	            if (number) {
	               	write(CLR);					
					write(HIW"\n───────────────────────────────────[0m\n"NOR);
					write(page(book,number));
	               	write(sprintf(HIW"─────────────────%-d─────────────────\n"NOR,
							number));
	               	input_to("back_off",ob, file);	
	               	return;
		       	}else {
		    	    	quit_help(ob);
		        		return;	
		    	}
	        }
        }  

        ob->delete_temp("marks/repeat_help");    
       	quit_help(ob);
}
