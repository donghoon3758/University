<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
	request.setCharacterEncoding("UTF-8");
	String name = request.getParameter("number");
	String id = request.getParameter("ID");
	String comment = request.getParameter("comment");
%>
<br> �۹�ȣ:<%=name%>
<br> ���̵�:<%=id%>
<br> �ڸ�Ʈ:<%=comment%>
