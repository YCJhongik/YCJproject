def sign_up() : #회원가입 1.1
    try :
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        CID = column_values[0]
        cname = column_values[1]
        ccontact = column_values[2]

        if CID != 'admin' :
            customerID.append(CID) #CID목록이 들어가있는 리스트 생성 후 CID 목록들 저장
        else :
            adminID.append(CID) # CID가 admin일 경우 adminID에 CID저장하여 접근자가관리자인지 판별하기 위한 리스트 생성

        cursor.execute("insert into customer values('" + CID + "', '" + cname + "', '" + ccontact + "')")
        conn.commit()

        w_file.write("1.1 회원가입\n")
        w_file.write(">" + CID + " "+ cname + " " + ccontact + "\n")
    except:
          conn.rollback()

def finish() : # 1.2 종료
    w_file.write("1.2. 종료")

def log_in1() : # 2.1 로그인
    try :
        global ID
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        ID = column_values[0]           #입력받은 CID값이 전역변수ID에 저장
        w_file.write("2.1 로그인\n")
        w_file.write(">" + ID + "\n")


    except:
          conn.rollback()



def pmodel_reserve() : #제품 렌탈 예약 2.2
    try :
        global ID
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        BID = column_values[0]
        pnum = column_values[1]
        rentaldue = column_values[2]

        w_file.write("2.2 제품렌탈 예약\n")     # 기본키 pnum을 통해서 pnum이 입력받은 값 과 일치하는 데이터 수정

        cursor.execute("update pmodel set rentaldue ='" + rentaldue + "' , CID = '"+ ID + "' where BID = '" + BID +"' and pnum = '" + pnum + "'" )
        conn.commit()

        cursor.execute("select ptype from pmodel where pnum = '" + pnum + "'")
        rows = cursor.fetchall()
        for cur_row in rows:
            ptype = cur_row[0]  # 첫번째 열의 값 : ptype
            w_file.write(">%s %s %s %s\n" % (BID, pnum, ptype, rentaldue))

    except:
          conn.rollback()

def pmodel_check() : #제품 렌탈 예약 조회 2.3
    try :
        global ID
        w_file.write("2.3 제품렌탈 예약 조회\n")

        cursor.execute("select BID,pnum,ptype,rentaldue from pmodel where CID = '"+ ID +"'") #로그인한 CID를 통해서 예약 조회
        rows = cursor.fetchall()
        for cur_row in rows:
            BID = cur_row[0]  # 첫번째 열의 값 : BID
            pnum = cur_row[1]  # 두번째 열의 값 : pnum
            ptype = cur_row[2]  # 세번째 열의 값 : ptype
            rentaldue = cur_row[3]  # 네번째 열의 값 : rentaldue
            w_file.write(">%s %s %s %s \n" % (BID, pnum, ptype, rentaldue))


    except:
          conn.rollback()

def pmodel_cancel() : #제품 렌탈 예약취소 2.4
    try :
        global ID
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        BID = column_values[0]
        pnum = column_values[1]

        w_file.write("2.4 제품렌탈 취소\n")

        #입력받은 데이터와 일치하는 조건 삭제
        cursor.execute("update pmodel set rentaldue =null , CID = null where BID = '" + BID +"' and pnum = '" + pnum + "'" )
        conn.commit()


        cursor.execute("select BID,pnum,ptype,rentaldue from pmodel where pnum = '" + pnum + "'")
        rows = cursor.fetchall()
        for cur_row in rows:
            BID = cur_row[0]  # 첫번째 열의 값 : BID
            pnum = cur_row[1]  # 두번째 열의 값 : pnum
            ptype = cur_row[2]  # 세번째 열의 값 : ptype
            rentaldue = cur_row[3]  # 네번째 열의 값 : rentaldue
            w_file.write(">%s %s %s %s \n" % (BID, pnum, ptype, rentaldue))
    except:
          conn.rollback()
def log_out1() : # 2.5
    try :
        global ID
        w_file.write("2.5로그아웃\n")
        w_file.write(">" + ID  + "\n")
        ID = ''
    except:
          conn.rollback()

def log_in2() : # 3.1 로그인
    try :
        global ID
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        ID = column_values[0]                   #입력받은 CID값이 전역변수ID에 저장
        w_file.write("3.1 로그인\n")
        w_file.write(">" + ID + "\n")
    except:
          conn.rollback()

def branch_sign() : #대리점 정보 등록 3.2
    try :
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        BID = column_values[0]
        bname = column_values[1]
        baddress = column_values[2]

        cursor.execute("insert into branch values('" + BID + "', '" + bname + "', '" + baddress + "')")
        conn.commit()
        w_file.write("3.2 대리점 정보 등록\n")
        w_file.write(">" + BID + " " + bname + " " + baddress  + "\n")
    except:
          conn.rollback()

def pmodel_sign() : #제품 정보 등록 3.3
    try :
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        BID = column_values[0]
        pnum = column_values[1]
        ptype = column_values[2]
        #입력받은 정보 제품 테이블에 삽입
        cursor.execute("insert into pmodel(BID, pnum, ptype) values('" + BID + "', '" + pnum + "', '" + ptype + "')")
        conn.commit()
        w_file.write("3.3 제품 정보 등록\n")
        w_file.write(">" + BID + " " + pnum + " " + ptype+ "\n")
    except:
          conn.rollback()

def rental_check() : #렌탈 예약내역 전체조회 3.4
    try :

        w_file.write("3.4 제품렌탈 예약 조회\n")
        # 예약 내역을 배열에 저장후 출력(조인을 이용하여 cname도 같이 출력)
        cursor.execute("""select customer.cname,customer.CID, pmodel.BID, pmodel.pnum, pmodel.ptype, pmodel.rentaldue
                                from customer,pmodel
                                where customer.CID = pmodel.CID""")
        rows = cursor.fetchall()
        for cur_row in rows:
            cname = cur_row[0]  # 첫번째 열의 값 : cname
            CID = cur_row[1]  # 두번째 열의 값 : CID
            BID = cur_row[2]  # 세번째 열의 값 : BID
            pnum = cur_row[3] # 네번째 열의 값 : pnum
            ptype = cur_row[4]# 다섯번째 열의 값 : ptype
            rentaldue = cur_row[5]# 여섯번째 열의 값 : rentaldue
            w_file.write("> %s %s %s %s %s %s\n" % (cname, CID, BID, pnum, ptype, rentaldue))

    except:
          conn.rollback()


def rental_check_num() : #렌탈 예약내역 전체조회 (모델번호 검색) 3.5
    try :
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        str = column_values[0]     #모델번호 입력 받은값을 str에 저장
        modelnum = list(str)       #문자열 str을 리스트 modelnum에 저장
        word = []                   #modelnum 리스트 사이사이에 '%'값을 집어넣기 위해서 for문 사용
        for i in range(0, len(modelnum)*2) :
            if i % 2 == 0:
                word.append('%')        # index가 짝수일떄마다 '%'삽입
            else:
                a = int((i - 1) / 2)    # index가 홀수일때 modelnum리스트 값 순차적으로 삽입
                word.append(modelnum[a])
        word.append('%')          #리스트의 마지막에 '%' 삽입

        search = "".join(word)    #리스트를 문자열로 바꾸어 %(문자)%(문자)%...%(문자)% 형태의 문자열 생성 (LIKE함수 사용시 입력받은 문자가 순차적으로 포함되도록 입력할 문자열)
        w_file.write("3.5 제품렌탈 예약 내역 조회(모델번호)\n")
        cursor.execute("""select customer.cname,customer.CID, pmodel.BID, pmodel.pnum, pmodel.ptype, pmodel.rentaldue
                                        from customer,pmodel
                                        where customer.CID = pmodel.CID and pmodel.pnum LIKE '""" + search + "'")  # pnum LIKE = search문자열을 통해서 구현
        rows = cursor.fetchall()
        for cur_row in rows:
            cname = cur_row[0]  # 첫번째 열의 값 : cname
            CID = cur_row[1]  # 두번째 열의 값 : CID
            BID = cur_row[2]  # 세번째 열의 값 : BID
            pnum = cur_row[3] # 네번째 열의 값 : pnum
            ptype = cur_row[4]# 다섯번째 열의 값 : ptype
            rentaldue = cur_row[5]# 여섯번째 열의 값 : rentaldue
            w_file.write("> %s %s %s %s %s %s\n" % (cname, CID, BID, pnum, ptype, rentaldue))

    except:
          conn.rollback()

def rental_check_CID() : #렌탈 예약내역 조회 (고객이름) 3.6
    try :
        line = r_file.readline()
        line = line.strip()
        column_values = line.split()
        str = column_values[0]     #CID 받은값을 str에 저장
        searchcname = list(str)       #문자열 str을 리스트 modelnum에 저장
        word = []                   #modelnum 리스트 사이사이에 '%'값을 집어넣기 위해서 for문 사용
        for i in range(0, len(searchcname)*2) :
            if i % 2 == 0:
                word.append('%')        # index가 짝수일떄마다 '%'삽입
            else:
                a = int((i - 1) / 2)    # index가 홀수일때 modelnum리스트 값 순차적으로 삽입
                word.append(searchcname[a])
        word.append('%')          #리스트의 마지막에 '%' 삽입

        search = "".join(word)    #리스트를 문자열로 바꾸어 %(문자)%(문자)%...%(문자)% 형태의 문자열 생성 (LIKE함수 사용시 입력받은 문자가 순차적으로 포함되도록 입력할 문자열)
        w_file.write("3.6  예약 내역 조회(고객이름)\n")
        cursor.execute("""select customer.cname,customer.CID, pmodel.BID, pmodel.pnum, pmodel.ptype, pmodel.rentaldue
                                        from customer,pmodel
                                        where customer.CID = pmodel.CID and customer.cname LIKE '""" + search + "'")  # pnum LIKE = search문자열을 통해서 구현
        rows = cursor.fetchall()
        for cur_row in rows:
            cname = cur_row[0]  # 첫번째 열의 값 : cname
            CID = cur_row[1]  # 두번째 열의 값 : CID
            BID = cur_row[2]  # 세번째 열의 값 : BID
            pnum = cur_row[3] # 네번째 열의 값 : pnum
            ptype = cur_row[4]# 다섯번째 열의 값 : ptype
            rentaldue = cur_row[5]# 여섯번째 열의 값 : rentaldue
            w_file.write("> %s %s %s %s %s %s\n" % (cname, CID, BID, pnum, ptype, rentaldue))

    except:
          conn.rollback()

def log_out2() : # 3.7 로그아웃
    try :
        global ID
        w_file.write("3.7로그아웃\n")
        w_file.write(">" + ID + "\n")
        ID = ''
    except:
          conn.rollback()

def doTask() :
    # 종료 메뉴(1 2)가 입력되기 전까지 반복함
    while True :
        # 입력파일에서 메뉴 숫자 2개 읽기
        line = r_file.readline()
        line = line.strip()
        menu_levels = line.split()

        menu_level_1 = int(menu_levels[0])
        menu_level_2 = int(menu_levels[1])


        # 메뉴 구분 및 해당 연산 수행
        if menu_level_1 == 1 :
            if menu_level_2 == 1 :
                sign_up()
            elif menu_level_2 == 2 :
                finish()
                break
        elif menu_level_1 == 2 :
            if menu_level_2 == 1 :
                log_in1()
                if ID not in customerID :
                    w_file.write("일치하는 ID가 없으므로 프로그램을 종료합니다")
                    break
            elif menu_level_2 == 2 :
                pmodel_reserve()
                if ID == '' :
                    w_file.write("로그인하지 않았으므로 프로그램을 종료합니다")
                    break
            elif menu_level_2 == 3 :
                pmodel_check()
                if ID == '' :
                    w_file.write("로그인하지 않았으므로 프로그램을 종료합니다")
                    break
            elif menu_level_2 == 4 :
                pmodel_cancel()
                if ID == '' :
                    w_file.write("로그인하지 않았으므로 프로그램을 종료합니다")
                    break
            elif menu_level_2 == 5 :
                log_out1()
        elif menu_level_1 == 3:
            if menu_level_2 == 1 :
                log_in2()
                if ID not in adminID :
                    w_file.write("관리자 ID가 일치하지 않으므로 종료를 실시합니다.\n")
                    break       #관리자 ID인 admin이 아닐시 프로그램 종료
            elif menu_level_2 == 2 :
                if ID in adminID :
                    branch_sign()
                else :
                    w_file.write("3.2 대리점 정보 등록\n")
                    w_file.write("관리자가 아니므로 프로그램을 종료합니다\n")
                    break
            elif menu_level_2 == 3 :
                if ID in adminID:
                    pmodel_sign()
                else:
                    w_file.write("3.3 제품 정보 등록\n")
                    w_file.write("관리자가 아니므로 프로그램을 종료합니다\n")
                    break
            elif menu_level_2 == 4 :
                if ID in adminID :
                    rental_check()
                else :
                    w_file.write("3.4 렌탈 예약 내역 전체 조회\n")
                    w_file.write("관리자가 아니므로 프로그램을 종료합니다\n")
                    break
            elif menu_level_2 == 5 :
                if ID in adminID :
                    rental_check_num()
                else :
                    w_file.write("3.5 렌탈 예약 내역 조회(모델번호)\n")
                    w_file.write("관리자가 아니므로 프로그램을 종료합니다\n")
            elif menu_level_2 == 6 :
                if ID in adminID :
                    rental_check_CID()
                else :
                    w_file.write("3.6 예약 내역 조회(모델번호)\n")
                    w_file.write("관리자가 아니므로 프로그램을 종료합니다\n")
            elif menu_level_2 == 7 :
                log_out2()



import pymysql

conn = pymysql.connect(host='localhost', user='root', password='root',
                       db='appliance_rental', charset='utf8mb4')

cursor = conn.cursor()

cursor.execute("set foreign_key_checks = 0")
cursor.execute("drop table if exists customer cascade")
cursor.execute("drop table if exists branch cascade")
cursor.execute("drop table if exists pmodel cascade")
cursor.execute("set foreign_key_checks = 1")
#고객,대리점,제품정보 테이블 생성
cursor.execute("""create table customer (
                    CID varchar(5) NOT NULL, 
                    cname varchar(20) NOT NULL, 
                    ccontact varchar(20) NOT NULL,
                    primary key (CID))""")
cursor.execute("""create table branch (
                    BID char(7) NOT NULL, 
                    bname varchar(20) NOT NULL, 
                    baddress varchar(20) NOT NULL, 
                    primary key (BID))""")
cursor.execute("""create table pmodel (
                    BID char(7) NOT NULL, 
                    pnum char(7) NOT NULL,
                    ptype varchar(20) NOT NULL,
                    CID char(7) ,
                    rentaldue varchar(20), 
                    FOREIGN KEY (BID) REFERENCES branch (BID) on delete cascade,
                    FOREIGN KEY (CID) REFERENCES customer (CID) on delete cascade,
                    primary key (pnum,BID));""")

global ID # CID의 전역변수 선언을 통해 다른 함수에서도 접근 가능하도록 설정
customerID = [] # 관리자를 제외한 CID 목록
adminID = [] # 관리자 CID

r_file = open("input.txt", "r", encoding='UTF8') #encoding='UTF8'을 안붙일시 한글미출력 오류로인해 붙였습니다
w_file = open("output.txt", "w", encoding='UTF8')



doTask()

cursor.execute("DROP TABLE pmodel")
cursor.execute("DROP TABLE customer")
cursor.execute("DROP TABLE branch")


r_file.close()
w_file.close()

conn.close()